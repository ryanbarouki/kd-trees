#include "Rect.h"
#include <math.h>


Rect::Rect(double xmin, double ymin, double xmax, double ymax) : m_xmin(xmin), m_ymin(ymin), m_xmax(xmax), m_ymax(ymax)
{

}

double Rect::xmin() const
{
	return m_xmin;
}
 
double Rect::xmax() const
{
	return m_xmax;
}

double Rect::ymin() const
{
	return m_ymin;
}
 
double Rect::ymax() const
{
	return m_ymax;
}

bool Rect::contains(Point const& p) const
{
	double x = p.x();
	double y = p.y();
	return (x > m_xmin) && (x < m_xmax) && (y > m_ymin) && (y < m_ymax);
}

bool Rect::intersects(Rect const& rect) const
{
	return this->m_xmax >= rect.m_xmin && this->m_ymax >= rect.m_ymin
		&& rect.m_xmax >= this->m_xmin && rect.m_ymax >= this->m_ymin;
}

double Rect::distanceTo(Point const& p) const
{
	double p_x = p.x();
	double p_y = p.y();
	double x = p_x;
	double y = p_y;

	if (contains(p)) { return -1; }
	if (p_x < m_xmin)
	{
		x = m_xmin;
	}
	if (p_y < m_ymin)
	{
		y = m_ymin;
	}
	if (p_x > m_xmax)
	{
		x = m_xmax;
	}
	if (p_y > m_ymax)
	{
		y = m_ymax;
	}

	double distsq = pow(p_x - x, 2) + pow(p_y - y, 2);
	return sqrt(distsq);
}
