#include "Point.h"
#include <math.h>

Point::Point(double x, double y) : m_x(x), m_y(y)
{

}

double Point::x() const
{
	return m_x;
}

double Point::y() const
{
	return m_y;
}

double Point::distanceTo(Point const& other) const
{
	return sqrt(pow(this->m_x - other.m_x, 2) + pow(this->m_y - other.m_y, 2));
}

int Point::compare(Point const& other, int level) const
{
	if (level == 0)
	{
		if (m_x < other.m_x) { return -1; }
		else if (m_x > other.m_x) { return 1; }
		else { return 0; }
	}
	else
	{
		if (m_y < other.m_y) { return -1; }
		else if (m_y > other.m_y) { return 1; }
		else { return 0; }
	}
}

bool Point::operator==(Point const& other) const
{
	return m_x == other.m_x && m_y == other.m_y;
}
