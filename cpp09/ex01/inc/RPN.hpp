#pragma once

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
	private:
		std::stack<double> _stack;
	public:
		RPN();
		RPN(char *args);
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		void calculate(char *args);
};
