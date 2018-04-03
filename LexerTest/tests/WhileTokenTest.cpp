#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(while_token, determining_if_stay_alone)
{
	ExpectTokens("while", { Token::WHILE });
}

TEST(while_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" while ", { Token::WHILE });
	ExpectTokens(";while;", { Token::SEMICOLON, Token::WHILE, Token::SEMICOLON });
}

TEST(while_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("while;", { Token::WHILE, Token::SEMICOLON });
	ExpectTokens(";while", { Token::SEMICOLON, Token::WHILE });
}

TEST(while_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1while1", { Token::UNKNOWN });
	ExpectTokens("1while1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1while1", { Token::UNKNOWN });
	ExpectTokens("1.1while1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1while1", { Token::UNKNOWN });
	ExpectTokens("1while1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(while_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"while\"", { Token::STRING_LITERAL });
	ExpectTokens("\" while \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1while1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";while;\"", { Token::STRING_LITERAL });
}

TEST(while_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//while", {});
	ExpectTokens("// while ", {});
	ExpectTokens("//1while1", {});
	ExpectTokens("//;while;", {});
	ExpectTokens("/*while*/", {});
	ExpectTokens("/* while */", {});
	ExpectTokens("/*1while1*/", {});
	ExpectTokens("/*;while;*/", {});
	ExpectTokens("/*while", {});
	ExpectTokens("/* while ", {});
	ExpectTokens("/*1while1", {});
	ExpectTokens("/*;while;", {});
}
