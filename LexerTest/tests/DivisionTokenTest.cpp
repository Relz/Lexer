#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(division_token, determining_if_stay_alone)
{
	ExpectTokens("/", { Token::DIVISION });
}

TEST(division_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" / ", { Token::DIVISION });
	ExpectTokens(";/;", { Token::SEMICOLON, Token::DIVISION, Token::SEMICOLON });
}

TEST(division_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("/;", { Token::DIVISION, Token::SEMICOLON });
	ExpectTokens(";/", { Token::SEMICOLON, Token::DIVISION });
}

TEST(division_token, determining_if_between_numbers)
{
	ExpectTokens("1/1", { Token::INTEGER, Token::DIVISION, Token::INTEGER });
	ExpectTokens("1/1.1", { Token::INTEGER, Token::DIVISION, Token::FLOAT });
	ExpectTokens("1.1/1", { Token::FLOAT, Token::DIVISION, Token::INTEGER });
	ExpectTokens("1.1/1.1", { Token::FLOAT, Token::DIVISION, Token::FLOAT });
}

TEST(division_token, not_determining_if_part_of_plus_assignment)
{
	ExpectTokens("/=", { Token::DIVISION_ASSIGNMENT });
	ExpectTokens("+/=", { Token::PLUS, Token::DIVISION_ASSIGNMENT });
	ExpectTokens("/=/", { Token::DIVISION_ASSIGNMENT, Token::DIVISION });
}

TEST(division_token, not_determining_if_in_character_literal)
{
	ExpectTokens("'/'", { Token::CHARACTER_LITERAL });
}

TEST(division_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"/\"", { Token::STRING_LITERAL });
	ExpectTokens("\" / \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1/1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";/;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"///\"", { Token::STRING_LITERAL });
}

TEST(division_token, not_determining_if_part_of_comment)
{
	ExpectTokens("///", {});
	ExpectTokens("// / ", {});
	ExpectTokens("//1/1", {});
	ExpectTokens("//;/;", {});
	ExpectTokens("/////", {});
	ExpectTokens("/////", {});
	ExpectTokens("// / //", {});
	ExpectTokens("//1/1//", {});
	ExpectTokens("//;/;//", {});
	ExpectTokens("///////", {});
	ExpectTokens("///", {});
	ExpectTokens("// / ", {});
	ExpectTokens("//1/1", {});
	ExpectTokens("//;/;", {});
	ExpectTokens("/////", {});
}
