#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int N): _N(N){}

Span::~Span(){}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_v = other._v;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_v.size() == _N)
		throw fullContainer();
	_v.push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw notEnoughNumbers();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	unsigned int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
	{
		if ((unsigned int)(tmp[i + 1] - tmp[i]) < min)
			min = tmp[i + 1] - tmp[i];
	}
	return min;
}

unsigned int Span::longestSpan()
{
	if (_v.size() < 2)
		throw notEnoughNumbers();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}
