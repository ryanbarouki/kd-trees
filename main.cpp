#include <iostream>
#include "KDTree.h"
#include "Point.h"

int main()
{
	KDTree tree;
	Point p1 = { 0.7,0.2 };
	Point p2 = { 0.5,0.4 };
	Point p3 = { 0.2,0.3 };
	Point p4 = { 0.4,0.7 };
	Point p5 = { 0.9,0.6 };
	
	tree.insert(p1);
	tree.insert(p2);
	tree.insert(p3);
	tree.insert(p4);
	tree.insert(p5);
	std::cout << tree.contains(Point{ 12,65 }) << std::endl;
	std::cout << tree.contains(Point{ 12,75 }) << std::endl;
	Rect rect(0, 0.5, 1, 1);
	std::vector<Point> pointsInRange = tree.range(rect);
	std::cout << "Hello, there. General Kenobi\n";
	return 0;
}