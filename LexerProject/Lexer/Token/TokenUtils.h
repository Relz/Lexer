#ifndef PROJECT_TOKENUTILS_H
#define PROJECT_TOKENUTILS_H

#include <string>
#include <stdexcept>
#include "Constant.h"
#include "Rule/Rule.h"
#include "Token.h"

class TokenUtils
{
public:
	static Token DetermineTokenFromString(const std::string & tokenString);

private:
	static bool IsLetterOrDigitSequence(const std::string & tokenString);

	static std::unordered_map<char, Token> _charsToOperatorTokens
			{
					{Operator::PLUS,     Token::PLUS},
					{Operator::MINUS,    Token::MINUS},
					{Operator::MULTIPLY, Token::MULTIPLY},
					{Operator::DIVISION, Token::DIVISION}
			};

	static std::unordered_map<std::string, Token> _stringsToKeywords
			{
					{Keyword::CLASS,           Token::CLASS},
					{Keyword::EXTENDS,         Token::EXTENDS},
					{Keyword::IMPLEMENTS,      Token::IMPLEMENTS},
					{Keyword::CONSTRUCTOR,     Token::CONSTRUCTOR},
					{Keyword::NOT_INITIALIZED, Token::NOT_INITIALIZED},
					{Keyword::PRIVATE,         Token::PRIVATE},
					{Keyword::PUBLIC,          Token::PUBLIC},
					{Keyword::GET,             Token::GET},
					{Keyword::SET,             Token::SET},
					{Keyword::FOR,             Token::FOR},
					{Keyword::WHILE,           Token::WHILE},
					{Keyword::DO,              Token::DO},
					{Keyword::RETURN,          Token::RETURN}
			};
};

#endif //PROJECT_TOKENUTILS_H
