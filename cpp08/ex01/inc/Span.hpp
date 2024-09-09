#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _v;
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);

		void addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		class fullContainer : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Container is full";
				}
		};
		
		class notEnoughNumbers : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Not enough numbers stored";
				}
		};
};

#endif