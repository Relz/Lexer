#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(class_token, determining_if_stay_alone)
{
	ExpectTokens("class", { Token::CLASS });
}

TEST(class_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" class ", { Token::CLASS });
	ExpectTokens(";class;", { Token::SEMICOLON, Token::CLASS, Token::SEMICOLON });
}

TEST(class_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("class;", { Token::CLASS, Token::SEMICOLON });
	ExpectTokens(";class", { Token::SEMICOLON, Token::CLASS });
}

TEST(class_token, not_determining_if_between_numbers)
{
	ExpectTokens("1class1", { Token::UNKNOWN });
	ExpectTokens("1class1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1class1", { Token::UNKNOWN });
	ExpectTokens("1.1class1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1E+1class1", { Token::UNKNOWN });
	ExpectTokens("1class1E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(class_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"class\"", { Token::STRING_LITERAL });
	ExpectTokens("\" class \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1class1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";class;\"", { Token::STRING_LITERAL });
}

TEST(class_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//class", { });
	ExpectTokens("// class ", { });
	ExpectTokens("//1class1", { });
	ExpectTokens("//;class;", { });
	ExpectTokens("/*class*/", { });
	ExpectTokens("/* class */", { });
	ExpectTokens("/*1class1*/", { });
	ExpectTokens("/*;class;*/", { });
	ExpectTokens("/*class", { });
	ExpectTokens("/* class ", { });
	ExpectTokens("/*1class1", { });
	ExpectTokens("/*;class;", { });
}
