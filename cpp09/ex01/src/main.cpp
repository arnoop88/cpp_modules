#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc < 2 || !isdigit(*argv[1]))
		std::cerr << "Invalid input" << std::endl;
	else
		RPN rpn(argv[1]);
}
