#include <iostream>
#include "Constant.h"
#include "Lexer/Lexer.h"

int main(int argc, char *argv[])
{
	if (argc < REQUIRED_ARGC)
	{
		std::cerr << NO_ARGUMENT_ERROR << "\n";
		return 1;
	}
	std::string inputFileName = argv[1];
	Lexer lexer(argv[1]);
	lexer.Print();
	return 0;
}
