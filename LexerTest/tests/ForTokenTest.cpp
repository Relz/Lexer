#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(for_token, determining_if_stay_alone)
{
	ExpectTokens("for", { Token::FOR });
}

TEST(for_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" for ", { Token::FOR });
	ExpectTokens(";for;", { Token::SEMICOLON, Token::FOR, Token::SEMICOLON });
}

TEST(for_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("for;", { Token::FOR, Token::SEMICOLON });
	ExpectTokens(";for", { Token::SEMICOLON, Token::FOR });
}

TEST(for_token, not_determining_if_between_numbers)
{
	ExpectTokens("1for1", { Token::UNKNOWN });
	ExpectTokens("1for1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1for1", { Token::UNKNOWN });
	ExpectTokens("1.1for1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1E+1for1", { Token::UNKNOWN });
	ExpectTokens("1for1E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER});
}

TEST(for_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"for\"", { Token::STRING_LITERAL });
	ExpectTokens("\" for \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1for1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";for;\"", { Token::STRING_LITERAL });
}

TEST(for_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//for", { });
	ExpectTokens("// for ", { });
	ExpectTokens("//1for1", { });
	ExpectTokens("//;for;", { });
	ExpectTokens("/*for*/", { });
	ExpectTokens("/* for */", { });
	ExpectTokens("/*1for1*/", { });
	ExpectTokens("/*;for;*/", { });
	ExpectTokens("/*for", { });
	ExpectTokens("/* for ", { });
	ExpectTokens("/*1for1", { });
	ExpectTokens("/*;for;", { });
}
