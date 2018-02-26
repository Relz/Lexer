#include "Constant.h"
#include "Lexer/Lexer.h"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc - 1 < REQUIRED_ARGC)
	{
		std::cerr << NO_ARGUMENT_ERROR << "\n";
		return EXIT_FAILURE;
	}
	std::string inputFileName = argv[1];
	Lexer lexer(inputFileName);
	TokenInformation tokenInformation;
	while (lexer.GetNextTokenInformation(tokenInformation))
	{
		std::cout << tokenInformation.ToString() << "\n";
	}
	return EXIT_SUCCESS;
}
