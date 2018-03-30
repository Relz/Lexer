#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(not_initialized_token, determining_if_stay_alone)
{
	ExpectTokens("NULL", { Token::NOT_INITIALIZED });
}

TEST(not_initialized_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" NULL ", { Token::NOT_INITIALIZED });
	ExpectTokens(";NULL;", { Token::SEMICOLON, Token::NOT_INITIALIZED, Token::SEMICOLON });
}

TEST(not_initialized_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("NULL;", { Token::NOT_INITIALIZED, Token::SEMICOLON });
	ExpectTokens(";NULL", { Token::SEMICOLON, Token::NOT_INITIALIZED });
}

TEST(not_initialized_token, not_determining_if_between_numbers)
{
	ExpectTokens("1NULL1", { Token::UNKNOWN });
	ExpectTokens("1NULL1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1NULL1", { Token::UNKNOWN });
	ExpectTokens("1.1NULL1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1NULL1", { Token::UNKNOWN });
	ExpectTokens("1NULL1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(not_initialized_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"NULL\"", { Token::STRING_LITERAL });
	ExpectTokens("\" NULL \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1NULL1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";NULL;\"", { Token::STRING_LITERAL });
}

TEST(not_initialized_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//NULL", { });
	ExpectTokens("// NULL ", { });
	ExpectTokens("//1NULL1", { });
	ExpectTokens("//;NULL;", { });
	ExpectTokens("/*NULL*/", { });
	ExpectTokens("/* NULL */", { });
	ExpectTokens("/*1NULL1*/", { });
	ExpectTokens("/*;NULL;*/", { });
	ExpectTokens("/*NULL", { });
	ExpectTokens("/* NULL ", { });
	ExpectTokens("/*1NULL1", { });
	ExpectTokens("/*;NULL;", { });
}
