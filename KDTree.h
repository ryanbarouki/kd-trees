#pragma once
#include "Point.h"
#include <memory>

class KDTree {
private:
	struct Node {
		Point point;
		std::unique_ptr<Node> lb; // pointer to left/bottom node
		std::unique_ptr<Node> rt; // pointer to right/top node

		Node(Point const& p);
	};
	int m_size;
	std::unique_ptr<Node> root;
public:
	KDTree();
	bool isEmpty() const { return m_size == 0; }
	int size() const { return m_size; }
	void insert(Point const& p);
	bool contains(Point const& p);
private:
	std::unique_ptr<Node> insert(std::unique_ptr<Node> node, Point const& p, int level);
	std::unique_ptr<Node> contains(std::unique_ptr<Node> node, Point const& p, int level);
};
