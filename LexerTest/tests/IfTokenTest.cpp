#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(if_token, determining_if_stay_alone)
{
	ExpectTokens("if", { Token::IF });
}

TEST(if_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" if ", { Token::IF });
	ExpectTokens(";if;", { Token::SEMICOLON, Token::IF, Token::SEMICOLON });
}

TEST(if_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("if;", { Token::IF, Token::SEMICOLON });
	ExpectTokens(";if", { Token::SEMICOLON, Token::IF });
}

TEST(if_token, not_determining_if_between_numbers)
{
	ExpectTokens("1if1", { Token::UNKNOWN });
	ExpectTokens("1if1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1if1", { Token::UNKNOWN });
	ExpectTokens("1.1if1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1E+1if1", { Token::UNKNOWN });
	ExpectTokens("1if1E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(if_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"if\"", { Token::STRING_LITERAL });
	ExpectTokens("\" if \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1if1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";if;\"", { Token::STRING_LITERAL });
}

TEST(if_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//if", { });
	ExpectTokens("// if ", { });
	ExpectTokens("//1if1", { });
	ExpectTokens("//;if;", { });
	ExpectTokens("/*if*/", { });
	ExpectTokens("/* if */", { });
	ExpectTokens("/*1if1*/", { });
	ExpectTokens("/*;if;*/", { });
	ExpectTokens("/*if", { });
	ExpectTokens("/* if ", { });
	ExpectTokens("/*1if1", { });
	ExpectTokens("/*;if;", { });
}
