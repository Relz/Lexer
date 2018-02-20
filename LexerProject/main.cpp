#include "Constant.h"
#include "Lexer/Lexer.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc - 1 < REQUIRED_ARGC)
	{
		cerr << NO_ARGUMENT_ERROR << "\n";
		return EXIT_FAILURE;
	}
	string inputFileName = argv[1];
	Lexer lexer(argv[1]);
	lexer.Print();
	return EXIT_SUCCESS;
}
