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

TEST(if_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1if1", { Token::UNKNOWN });
	ExpectTokens("1if1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1if1", { Token::UNKNOWN });
	ExpectTokens("1.1if1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1if1", { Token::UNKNOWN });
	ExpectTokens("1if1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
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
	ExpectTokens("//if", { Token::LINE_COMMENT });
	ExpectTokens("// if ", { Token::LINE_COMMENT });
	ExpectTokens("//1if1", { Token::LINE_COMMENT });
	ExpectTokens("//;if;", { Token::LINE_COMMENT });
	ExpectTokens("/*if*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/* if */", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1if1*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;if;*/", { Token::BLOCK_COMMENT });
	ExpectTokens("/*if", { Token::BLOCK_COMMENT });
	ExpectTokens("/* if ", { Token::BLOCK_COMMENT });
	ExpectTokens("/*1if1", { Token::BLOCK_COMMENT });
	ExpectTokens("/*;if;", { Token::BLOCK_COMMENT });
}
