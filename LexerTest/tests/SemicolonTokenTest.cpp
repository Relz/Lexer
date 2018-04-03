#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(semicolon_token, determining_if_stay_alone)
{
	ExpectTokens(";", { Token::SEMICOLON });
}

TEST(semicolon_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" ; ", { Token::SEMICOLON });
	ExpectTokens("+;+", { Token::PLUS, Token::SEMICOLON, Token::PLUS });
}

TEST(semicolon_token, determining_if_stay_near_delimiter)
{
	ExpectTokens(";+", { Token::SEMICOLON, Token::PLUS });
	ExpectTokens("+;", { Token::PLUS, Token::SEMICOLON });
}

TEST(semicolon_token, determining_if_stay_between_numbers)
{
	ExpectTokens("1;1", { Token::INTEGER, Token::SEMICOLON, Token::INTEGER });
	ExpectTokens("1;1.1", { Token::INTEGER, Token::SEMICOLON, Token::FLOAT });
	ExpectTokens("1.1;1", { Token::FLOAT, Token::SEMICOLON, Token::INTEGER });
	ExpectTokens("1.1;1.1", { Token::FLOAT, Token::SEMICOLON, Token::FLOAT });
	ExpectTokens("1_E+1;1", { Token::EXPONENTIAL, Token::SEMICOLON, Token::INTEGER });
	ExpectTokens("1;1_E+1", { Token::INTEGER, Token::SEMICOLON, Token::EXPONENTIAL });
}

TEST(semicolon_token, not_determining_if_in_character_literal)
{
	ExpectTokens("';'", { Token::CHARACTER_LITERAL });
}

TEST(semicolon_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\";\"", { Token::STRING_LITERAL });
	ExpectTokens("\" ; \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1;1\"", { Token::STRING_LITERAL });
	ExpectTokens("\"+;+\"", { Token::STRING_LITERAL });
}

TEST(semicolon_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//;", { });
	ExpectTokens("// ; ", { });
	ExpectTokens("//1;1", { });
	ExpectTokens("//;;;", { });
	ExpectTokens("/*;*/", { });
	ExpectTokens("/* ; */", { });
	ExpectTokens("/*1;1*/", { });
	ExpectTokens("/*;;;*/", { });
	ExpectTokens("/*;", { });
	ExpectTokens("/* ; ", { });
	ExpectTokens("/*1;1", { });
	ExpectTokens("/*;;;", { });
}
