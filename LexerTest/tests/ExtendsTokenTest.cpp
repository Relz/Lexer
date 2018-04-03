#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(extends_token, determining_if_stay_alone)
{
	ExpectTokens("extends", { Token::EXTENDS });
}

TEST(extends_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" extends ", { Token::EXTENDS });
	ExpectTokens(";extends;", { Token::SEMICOLON, Token::EXTENDS, Token::SEMICOLON });
}

TEST(extends_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("extends;", { Token::EXTENDS, Token::SEMICOLON });
	ExpectTokens(";extends", { Token::SEMICOLON, Token::EXTENDS });
}

TEST(extends_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1extends1", { Token::UNKNOWN });
	ExpectTokens("1extends1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1extends1", { Token::UNKNOWN });
	ExpectTokens("1.1extends1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1extends1", { Token::UNKNOWN });
	ExpectTokens("1extends1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(extends_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"extends\"", { Token::STRING_LITERAL });
	ExpectTokens("\" extends \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1extends1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";extends;\"", { Token::STRING_LITERAL });
}

TEST(extends_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//extends", { });
	ExpectTokens("// extends ", { });
	ExpectTokens("//1extends1", { });
	ExpectTokens("//;extends;", { });
	ExpectTokens("/*extends*/", { });
	ExpectTokens("/* extends */", { });
	ExpectTokens("/*1extends1*/", { });
	ExpectTokens("/*;extends;*/", { });
	ExpectTokens("/*extends", { });
	ExpectTokens("/* extends ", { });
	ExpectTokens("/*1extends1", { });
	ExpectTokens("/*;extends;", { });
}
