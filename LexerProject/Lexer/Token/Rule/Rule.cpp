#include "Rule.h"

bool Rule::IsLetter(char ch)
{
	return _letters.find(ch) != _letters.end();
}

bool Rule::IsDigit(char ch)
{
	return _digits.find(ch) != _digits.end();
}
