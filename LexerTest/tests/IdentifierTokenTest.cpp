#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(identifier_token, determining_if_stay_alone)
{
	ExpectTokens("_", { Token::IDENTIFIER });
	ExpectTokens("id", { Token::IDENTIFIER });
	ExpectTokens("_id", { Token::IDENTIFIER });
	ExpectTokens("_id_", { Token::IDENTIFIER });
	ExpectTokens("_i_d_", { Token::IDENTIFIER });
	ExpectTokens("1id", { Token::UNKNOWN });
	ExpectTokens("i1d", { Token::IDENTIFIER });
}

TEST(identifier_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" id ", { Token::IDENTIFIER });
	ExpectTokens(";id;", { Token::SEMICOLON, Token::IDENTIFIER, Token::SEMICOLON });
}

TEST(identifier_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("id;", { Token::IDENTIFIER, Token::SEMICOLON });
	ExpectTokens(";id", { Token::SEMICOLON, Token::IDENTIFIER });
}

TEST(identifier_token, not_determining_if_stay_between_numbers)
{
	ExpectTokens("1id1", { Token::UNKNOWN });
	ExpectTokens("1id1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1.1id1", { Token::UNKNOWN });
	ExpectTokens("1.1id1.1", { Token::UNKNOWN, Token::DOT, Token::INTEGER });
	ExpectTokens("1_E+1id1", { Token::UNKNOWN });
	ExpectTokens("1id1_E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
}

TEST(identifier_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"id\"", { Token::STRING_LITERAL });
	ExpectTokens("\" id \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1id1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";id;\"", { Token::STRING_LITERAL });
}

TEST(identifier_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//id", { });
	ExpectTokens("// id ", { });
	ExpectTokens("//1id1", { });
	ExpectTokens("//;id;", { });
	ExpectTokens("/*id*/", { });
	ExpectTokens("/* id */", { });
	ExpectTokens("/*1id1*/", { });
	ExpectTokens("/*;id;*/", { });
	ExpectTokens("/*id", { });
	ExpectTokens("/* id ", { });
	ExpectTokens("/*1id1", { });
	ExpectTokens("/*;id;", { });
}
