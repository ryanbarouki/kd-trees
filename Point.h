#pragma once

class Point {
private:
	double m_x, m_y;
public:
	Point(double x, double y);
	Point() = default;
	double x() const;
	double y() const;
	double distanceTo(Point const& other) const;
	int compare(Point const& other, int level) const;
	bool operator==(Point const& other) const;
};
