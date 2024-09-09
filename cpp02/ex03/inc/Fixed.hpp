#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int	_val;
	static const int _point = 8;
public:
	Fixed();
	Fixed(const float val);
	Fixed(const int val);
	~Fixed();
	Fixed(Fixed const &copy);

	Fixed &operator=(Fixed const &copy);

	bool operator>(Fixed const &copy) const;
	bool operator<(Fixed const &copy) const;
	bool operator>=(Fixed const &copy) const;
	bool operator<=(Fixed const &copy) const;
	bool operator==(Fixed const &copy) const;
	bool operator!=(Fixed const &copy) const;

	Fixed operator+(Fixed const &copy) const;
	Fixed operator-(Fixed const &copy) const;
	Fixed operator*(Fixed const &copy) const;
	Fixed operator/(Fixed const &copy) const;

	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int val);
	Fixed operator--(int val);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif
