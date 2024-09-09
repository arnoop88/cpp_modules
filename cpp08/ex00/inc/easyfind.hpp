#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Number not found";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), n);
	if (iter == container.end())
		throw NotFoundException();
	return iter;
}

#endif