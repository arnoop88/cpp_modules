#ifndef __POINT_HPP__
# define __POINT_HPP__

# include "Fixed.hpp"
# include <iostream>
# include <cmath>

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(float const x, float const y);
		~Point();
		Point(Point const &copy);
		Point &operator=(Point const &copy);

		Fixed const &getX() const;
		Fixed const &getY() const;
};

#endif
