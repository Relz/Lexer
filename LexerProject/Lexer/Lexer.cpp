#include "Lexer.h"

Lexer::Lexer(const std::string &input)
	: _input(input)
{
	std::string scanned;
	std::string delimiter;
	while (_input.Scan(scanned, delimiter, SCANNER_DELIMITERS))
	{
		std::cout << scanned << " " << delimiter << '\n';
	}
}
