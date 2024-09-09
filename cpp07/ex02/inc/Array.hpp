#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
	private:
		T				*_arr;
		unsigned int	_size;

	public:
		Array(): _size(0)
		{
			_arr = new T[_size];
		}
		Array(unsigned int n): _size(n)
		{
			_arr = new T[_size];
		}
		~Array()
		{
			delete [] _arr;
		}
		Array(const Array &other)
		{
			operator=(other);
		}
		Array& operator=(Array const &other)
		{
			_size = other._size;
			_arr = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_arr[i] = other._arr[i];
			return *this;
		}
		T& operator[](unsigned int i)
		{
			if (i >= _size)
				throw std::exception();
			return _arr[i];
		}
		unsigned int size()
		{
			return _size;
		}
};
