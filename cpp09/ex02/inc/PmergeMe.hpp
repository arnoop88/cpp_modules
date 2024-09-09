#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include <algorithm>
#include <ctime>

class PmergeMe
{
	private:
		std::deque<int> _deque;
		std::list<int> _list;
	public:
		PmergeMe();
		PmergeMe(char **args);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		int parse(char **args);
		void display(std::string msg);

		template <typename T>
		void sort(T &container);
};
