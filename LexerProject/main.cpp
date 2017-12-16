#include <iostream>
#include "Constant.h"
#include "Lexer/Lexer.h"

int main(int argc, char *argv[])
{
	if (argc < REQUIRED_ARGC)
	{
		std::cerr << "Ошибка: не указан файл с исходным кодом\n";
		return 1;
	}
	std::string inputFileName = argv[1];
	Lexer lexer(argv[1]);
	return 0;
}