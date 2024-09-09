#include "Fixed.hpp"

Fixed::Fixed(): _val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	_val = val * pow(2, _point);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
{
	_val = val * pow(2, _point);
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_val = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _val;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_val = raw;
}

float Fixed::toFloat(void) const
{
	return _val * pow(2, -_point);
}

int Fixed::toInt(void) const
{
	return _val * pow(2, -_point);
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}
