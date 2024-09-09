#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(char *args)
{
	calculate(args);
}

RPN::~RPN(){}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	_stack = other._stack;
	return *this;
}

static bool isOperand(std::string token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::calculate(char *args)
{
	double num;
	std::stringstream ss(args);
	std::string token;
	double a;
	double b;
	while (ss >> token)
	{
		if (std::stringstream(token) >> num)
			_stack.push(num);
		else if (!isOperand(token))
		{
			std::cerr << "Invalid input" << std::endl;
			return;
		}
		else
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Too much operators" << std::endl;
				return;
			}
			if (token == "+")
			{
				b = _stack.top();
				_stack.pop();
				a = _stack.top();
				_stack.pop();
				_stack.push(a + b);
			}
			else if (token == "-")
			{
				b = _stack.top();
				_stack.pop();
				a = _stack.top();
				_stack.pop();
				_stack.push(a - b);
			}
			else if (token == "*")
			{
				b = _stack.top();
				_stack.pop();
				a = _stack.top();
				_stack.pop();
				_stack.push(a * b);
			}
			else if (token == "/")
			{
				b = _stack.top();
				_stack.pop();
				a = _stack.top();
				_stack.pop();
				_stack.push(a / b);
			}
		}
	}
	if (_stack.size() > 1)
		std::cout << "Too much operands" << std::endl;
	else
		std::cout << _stack.top() << std::endl;
}
