#include "KDTree.h"

KDTree::KDTree() : m_size(0), root(nullptr)
{
}

void KDTree::insert(Point const& p)
{
	// only supports values in the unit square at the moment, just need to add some bounds into constructor
	root = insert(std::move(root), p, Rect{ 0,0,1,1 }, 0);
}

// internal insert to allow recursive insert
std::unique_ptr<KDTree::Node> KDTree::insert(std::unique_ptr<Node> node, Point const& p, Rect const& rect, int level)
{
	if (node == nullptr)
	{
		return std::make_unique<Node>(p, rect);
	}
	if (p.compare(node->point, level) == -1) // p < node.p
	{
		Rect tempRect;
		if (level == 0) { tempRect = { rect.xmin(), rect.ymin(), node->point.x(), rect.ymax() }; }
		else { tempRect = { rect.xmin(), rect.ymin(), rect.xmax(), node->point.y() }; }
		node->lb = insert(std::move(node->lb), p, tempRect, (level + 1) % 2);
	}
	else // p >= node.p
	{	
		Rect tempRect;
		if (level == 0) { tempRect = { node->point.x(), rect.ymin(), rect.xmax(), rect.ymax() }; }
		else { tempRect = { rect.xmin(), node->point.y(), rect.xmax(), rect.ymax()}; }
		node->rt = insert(std::move(node->rt), p, node->rect, (level + 1) % 2);
	}
	
	return std::move(node);
}

bool KDTree::contains(Point const& p)
{
	Node* temp = root.get();
	int level = 0;
	while (temp != nullptr)
	{
		if (temp->point == p)
		{
			return true;
		}
		else if (p.compare(temp->point, level) == -1)
		{
			temp = temp->lb.get();
		}
		else
		{
			temp = temp->rt.get();
		}
		level = (level + 1) % 2;
	}
	return false;
}


KDTree::Node::Node(Point const& p, Rect const& rect) : point(p), rect(rect), lb(nullptr), rt(nullptr)
{
}

std::vector<Point> KDTree::range(Node* node, Rect const& rect, std::vector<Point>& points)
{
	if (node == nullptr) { return points; }
	if (rect.contains(node->point))
	{
		points.push_back(node->point);
	}
	if (node->lb != nullptr && rect.intersects(node->lb->rect))
	{
		points = range(node->lb.get(), rect, points);
	}
	if (node->rt != nullptr && rect.intersects(node->rt->rect))
	{
		points = range(node->rt.get(), rect, points);
	}
	return points;
}

std::vector<Point> KDTree::range(Rect const& rect)
{
	Node* temp_ptr = root.get();
	std::vector<Point> res;
	return range(temp_ptr, rect, res);
}
