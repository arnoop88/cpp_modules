#include "BitcoinExchange.hpp"

bool check_date(std::string date)
{
	char *endptr = NULL;

	if (date.size() != 10)
		return false;
	int year = std::strtol(date.substr(0, 4).c_str(), &endptr, 10);
	if (*endptr != '\0' || year < 2009 || year > 9999 || date[4] != '-')
		return false;
	endptr = NULL;
	int month = std::strtol(date.substr(5, 2).c_str(), &endptr, 10);
	if (*endptr != '\0' || month < 1 || month > 12 || date[7] != '-')
		return false;
	endptr = NULL;
	int day = std::strtol(date.substr(8, 2).c_str(), &endptr, 10);
	if (*endptr != '\0' || day < 1 || day > 31 || (year == 2009 && month == 01 && day == 01))
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2)
	{
		int max_day = 28;
		if (year % 4 == 0)
			max_day = 29;
		if ((year % 100 == 0 && year % 400 != 0) || (year % 400 == 0 && year % 4000 == 0))
			max_day = 28;
		if (day > max_day)
			return false;
	}
	return true;
}

int binary_search(std::string date, const std::vector<std::pair<std::string, double> > &vector2)
{
	int left = 0;
	int right = vector2.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (vector2[mid].first == date)
			return mid;
		else if (vector2[mid].first < date)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return right;
}

void output(const std::vector<std::pair<std::string, double> > &vector1, const std::vector<std::pair<std::string, double> > &vector2)
{
	for(std::vector<std::pair<std::string, double> >::const_iterator it = vector1.begin() + 1; it < vector1.end(); it++)
	{
		if (it->second == -1)
			std::cout << it->first << std::endl;
		else
			std::cout << it->first << " => " << it->second << " = " << it->second * vector2[binary_search(it->first, vector2)].second << std::endl;
	}
}

void parse(std::ifstream &infile, std::vector<std::pair<std::string, double> > &vector, int mode)
{
	int pos;
	std::string line;
	std::string date;
	double val;
	while(std::getline(infile, line))
	{
		if (mode == 3)
			pos = line.find(" | ");
		else
			pos = line.find(",");
		if (pos == -1)
		{
			vector.push_back(std::make_pair("Error: invalid input => " + line, -1));
			continue;
		}
		date = line.substr(0, pos);
		if (!check_date(date))
		{
			vector.push_back(std::make_pair("Error: invalid date => " + line, -1));
			continue;
		}
		std::stringstream ss(line.substr(pos + mode));
		if (!(ss >> val) || (val < 0 || val > 1000))
		{
			vector.push_back(std::make_pair("Error: invalid number => " + line.substr(pos + mode), -1));
			continue;
		}
		vector.push_back(std::make_pair(date, val));
	}
}
