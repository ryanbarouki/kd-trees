#include <iostream>
#include "KDTree.h"
#include "Point.h"

int main()
{
	KDTree tree;
	Point p1 = { 23,45 };
	Point p2 = { 12,45 };
	Point p3 = { 12,65 };
	
	tree.insert(p1);
	tree.insert(p2);
	tree.insert(p3);
	std::cout << tree.contains(Point{ 12,65 }) << std::endl;
	std::cout << tree.contains(Point{ 12,75 }) << std::endl;
	std::cout << "Hello, there. General Kenobi\n";
	return 0;
}