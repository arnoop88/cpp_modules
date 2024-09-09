#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(char **args)
{
	if (parse(args))
		return;
	std::clock_t start = std::clock();
	sort(_deque);
	std::clock_t end = std::clock();
	double time = static_cast<double>(end - start) / (double)CLOCKS_PER_SEC * 1000;
	std::cout << "deque process time: " << time << " us" << std::endl;
	start = clock();
	sort(_list);
	end = clock();
	time = static_cast<double>(end - start) / (double)CLOCKS_PER_SEC * 1000;
	std::cout << "list process time: " << time << " us" << std::endl;
	display("sorted:");
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	_deque = other._deque;
	_list = other._list;
	return *this;
}

void PmergeMe::display(std::string msg)
{
	std::cout << msg;
	for (std::deque<int>::iterator it = _deque.begin(); it < _deque.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

int PmergeMe::parse(char **args)
{
	int num;
	for (int i = 1; args[i]; i++)
	{
		std::stringstream ss(args[i]);
		if (!(ss >> num) || num < 0)
		{
			std::cerr << "Error: Invalid arguments" << std::endl;
			return 1;
		}
		_deque.push_back(num);
		_list.push_back(num);
	}
	display("unsorted:");
	return 0;
}

template <typename T>
void PmergeMe::sort(T &container)
{
	T pairs;
	typename T::iterator it = container.begin();
	while (it != container.end())
	{
		int first = *it;
		++it;
		if (it != container.end())
		{
			int second = *it;
			++it;
			if (first > second)
				std::swap(first, second);
			pairs.push_back(first);
			pairs.push_back(second);
		}
		else
			pairs.push_back(first);
	}
	T res;
	it = pairs.begin();
	res.push_back(*it);
	++it;
	while (it != pairs.end())
	{
		int num = *it;
		++it;
		typename T::iterator pos = std::lower_bound(res.begin(), res.end(), num);
		res.insert(pos, num);
	}
	container.clear();
    for (it = res.begin(); it != res.end(); ++it)
        container.push_back(*it);
}
