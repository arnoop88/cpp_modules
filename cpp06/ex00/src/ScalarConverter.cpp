#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return *this;
}

static bool isCharLiteral(const std::string &str)
{
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

static bool isDisplayable(const int c)
{
	return (c >= 32 && c <= 126);
}

static bool isPseudoLiteral(const std::string &str)
{
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff");
}

static void convert_char(const std::string &str)
{
	std::cout << "char: ";
	if (isCharLiteral(str))
		std::cout << "'" << str[1] << "'" << std::endl;
	else if (isPseudoLiteral(str))
		std::cout << "impossible" << std::endl;
	else
	{
		std::istringstream	iss(str);
		int					i;

		if (iss >> i)
		{
			if (isDisplayable(i))
				std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
			else
				std::cout << "non displayable" << std::endl;
		}
		else
			std::cout << "impossible" << std::endl;
	}
}

static void convert_int(const std::string &str)
{
	std::cout << "int: ";
	if (isCharLiteral(str))
		std::cout << static_cast<int>(str[1]) << std::endl;
	else if (isPseudoLiteral(str))
		std::cout << "impossible" << std::endl;
	else
	{
		std::istringstream	iss(str);
		int					i;

		if (iss >> i)
			std::cout << i << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}

static void convert_float(const std::string &str)
{
	std::cout << "float: ";
	if (isCharLiteral(str))
		std::cout << static_cast<float>(str[1]) << ".0f" << std::endl;
	else if (isPseudoLiteral(str))
	{
		if (str == "nan" || str == "nanf")
			std::cout << "nanf" << std::endl;
		else if (str == "+inf" || str == "+inff")
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
	{
		std::istringstream	iss(str);
		float				f;

		if (iss >> f)
			std::cout << f << ".0f" << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}

static void convert_double(const std::string &str)
{
	std::cout << "double: ";
	if (isCharLiteral(str))
		std::cout << static_cast<float>(str[1]) << ".0" << std::endl;
	else if (isPseudoLiteral(str))
	{
		if (str == "nan" || str == "nanf")
			std::cout << "nan" << std::endl;
		else if (str == "+inf" || str == "+inff")
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
	{
		std::istringstream	iss(str);
		double				d;

		if (iss >> d)
			std::cout << d << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &str)
{
	convert_char(str);
	convert_int(str);
	convert_float(str);
	convert_double(str);
}
