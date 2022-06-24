#ifndef POINT2D_H
#define POINT2D_H

#include <cmath>


class Point2d
{

private:
	double m_x{0.0};
	double m_y{0.0};

public:
	Point2d(double x=0.0, double y=0.0) : m_x{x}, m_y{y}
	{
	}

	void printPoint2d() const 
	{
    	std::cout << "point2d(" << m_x <<", "<< m_y << ")" <<'\n';
	}

/*	double distanceTo(Point2d p)
	{
		return (static_cast<int>( std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y)) ) );
	}			
*/
	friend double distanceFrom(const Point2d& p1, const Point2d& p2);
};

double distanceFrom(const Point2d& p1, const Point2d& p2)
{
	return (static_cast<int>( std::sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) + (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y)) ) );
}

#endif // POINT2D_H