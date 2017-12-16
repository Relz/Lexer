#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H

#include <string>
#include <vector>
#include "Constant.h"
#include "Input/Input.h"
#include "Token/TokenUtils.h"

class Lexer
{
public:
	explicit Lexer(const std::string &input);

private:
	CInput _input;
};

#endif //LEXER_LEXER_H
