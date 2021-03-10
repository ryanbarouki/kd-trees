#pragma once
#include "Point.h"
#include "Rect.h"
#include <memory>
#include <vector>

class KDTree {
private:
	struct Node {
		Point point;
		Rect rect;
		std::unique_ptr<Node> lb; // pointer to left/bottom node
		std::unique_ptr<Node> rt; // pointer to right/top node

		Node(Point const& p, Rect const& rect);
	};
	int m_size;
	std::unique_ptr<Node> root;
public:
	KDTree();
	bool isEmpty() const { return m_size == 0; }
	int size() const { return m_size; }
	void insert(Point const& p);
	bool contains(Point const& p);
	std::vector<Point> range(Rect const& rect);
private:
	std::unique_ptr<Node> insert(std::unique_ptr<Node> node, Point const& p, Rect const& rect, int level);
	std::vector<Point> range(Node* node, Rect const& rect, std::vector<Point>& points);
};
