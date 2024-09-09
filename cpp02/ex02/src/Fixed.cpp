#include "Fixed.hpp"

Fixed::Fixed(): _val(0)
{
}

Fixed::Fixed(const int val)
{
	_val = val * pow(2, _point);
}

Fixed::Fixed(const float val)
{
	_val = val * pow(2, _point);
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
	_val = copy.getRawBits();
	return *this;
}

bool Fixed::operator>(Fixed const &copy) const
{
	return (this->toFloat() > copy.toFloat());
}

bool Fixed::operator<(Fixed const &copy) const
{
	return (this->toFloat() < copy.toFloat());
}

bool Fixed::operator>=(Fixed const &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

bool Fixed::operator<=(Fixed const &copy) const
{
	return (this->toFloat() <= copy.toFloat());
}

bool Fixed::operator==(Fixed const &copy) const
{
	return (this->toFloat() == copy.toFloat());
}

bool Fixed::operator!=(Fixed const &copy) const
{
	return (this->toFloat() != copy.toFloat());
}

Fixed Fixed::operator+(Fixed const &copy) const
{
	Fixed res = this->toFloat() + copy.toFloat();
	return res;
}

Fixed Fixed::operator-(Fixed const &copy) const
{
	Fixed res = this->toFloat() - copy.toFloat();
	return res;
}

Fixed Fixed::operator*(Fixed const &copy) const
{
	Fixed res = this->toFloat() * copy.toFloat();
	return res;
}

Fixed Fixed::operator/(Fixed const &copy) const
{
	Fixed res = this->toFloat() / copy.toFloat();
	return res;
}

Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator++(int val)
{
	Fixed tmp = *this;

	if (!val)
		val = 1;
	this->setRawBits(this->getRawBits() + val);
	return tmp;
}

Fixed Fixed::operator--(int val)
{
	Fixed tmp = *this;

	if (!val)
		val = 1;
	this->setRawBits(this->getRawBits() - val);
	return tmp;
}

int Fixed::getRawBits( void ) const
{
	return _val;
}

void Fixed::setRawBits( int const raw )
{
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

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}
