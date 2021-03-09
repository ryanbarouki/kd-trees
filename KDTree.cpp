#include "KDTree.h"

KDTree::KDTree() : m_size(0), root(nullptr)
{
}

void KDTree::insert(Point const& p)
{
	root = insert(std::move(root), p, 0);
}

// internal insert to allow recursive insert
std::unique_ptr<KDTree::Node> KDTree::insert(std::unique_ptr<Node> node, Point const& p, int level)
{
	if (node == nullptr)
	{
		return std::make_unique<Node>(p);
	}
	if (p.compare(node->point, level) == -1) // p < node.p
	{
		node->lb = insert(std::move(node->lb), p, (level + 1) % 2);
	}
	else // p >= node.p
	{
		node->rt = insert(std::move(node->rt), p, (level + 1) % 2);
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


KDTree::Node::Node(Point const& p) : point(p), lb(nullptr), rt(nullptr)
{
}
