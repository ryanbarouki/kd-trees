#include "Rect.h"


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
	return (m_xmin < p.x() < m_xmax) && (m_ymin < p.y() < m_ymax);
}

bool Rect::intersects(Rect const& rect) const
{
	return this->m_xmax >= rect.m_xmin && this->m_ymax >= rect.m_ymin
		&& rect.m_xmax >= this->m_xmin && rect.m_ymax >= this->m_ymin;
}
