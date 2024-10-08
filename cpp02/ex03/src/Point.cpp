#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{}

Point::Point(float const x, float const y): _x(x), _y(y)
{}

Point::Point(Point const &copy)
{
	*this = copy;
}

Point::~Point()
{}

Point &Point::operator=(Point const &copy)
{
	(void)copy;
	return *this;
}

Fixed const &Point::getX() const
{
	return _x;
}

Fixed const &Point::getY() const
{
	return _y;
}
