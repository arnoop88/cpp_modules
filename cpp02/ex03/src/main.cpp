#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	std::cout << std::boolalpha

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 0): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 0)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(3, 2): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(3, 1)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(1, 2): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(1, 2)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(2, 3): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(2, 3)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0.1, 0.01): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0.1f, 0.01f)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(10, 0.01): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(10, 0.01f)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, -0.01): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, -0.01f)) << std::endl;
	
	return 0;
}
