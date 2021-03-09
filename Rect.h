#pragma once
#include "Point.h"

class Rect {
private:
	double m_xmin, m_xmax, m_ymin, m_ymax;
public:
	Rect(double xmin, double ymin, double xmax, double ymax);
	double xmin() const;
	double xmax() const;
	double ymin() const;
	double ymax() const;
	bool contains(Point const& p) const;
	bool intersects(Rect const& rect) const;
};