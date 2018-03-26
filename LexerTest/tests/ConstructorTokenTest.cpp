#include "TestHelper.h"

using namespace std;

TEST(constructor_token, determining_if_stay_alone)
{
	ExpectTokens("Constructor", { Token::CONSTRUCTOR });
}

TEST(constructor_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" Constructor ", { Token::CONSTRUCTOR });
	ExpectTokens(";Constructor;", { Token::SEMICOLON, Token::CONSTRUCTOR, Token::SEMICOLON });
}

TEST(constructor_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("Constructor;", { Token::CONSTRUCTOR, Token::SEMICOLON });
	ExpectTokens(";Constructor", { Token::SEMICOLON, Token::CONSTRUCTOR });
}

TEST(constructor_token, not_determining_if_between_numbers)
{
	ExpectTokens("1Constructor1", { Token::UNKNOWN });
	ExpectTokens("1Constructor1.1", { Token::UNKNOWN });
	ExpectTokens("1.1Constructor1", { Token::UNKNOWN });
	ExpectTokens("1.1Constructor1.1", { Token::UNKNOWN });
	ExpectTokens("1E+1Constructor1", { Token::UNKNOWN });
	ExpectTokens("1Constructor1E+1", { Token::UNKNOWN });
}

TEST(constructor_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"Constructor\"", { Token::STRING_LITERAL });
	ExpectTokens("\" Constructor \"", { Token::STRING_LITERAL });
	ExpectTokens("\"1Constructor1\"", { Token::STRING_LITERAL });
	ExpectTokens("\";Constructor;\"", { Token::STRING_LITERAL });
}

TEST(constructor_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//Constructor", { });
	ExpectTokens("// Constructor ", { });
	ExpectTokens("//1Constructor1", { });
	ExpectTokens("//;Constructor;", { });
	ExpectTokens("/*Constructor*/", { });
	ExpectTokens("/* Constructor */", { });
	ExpectTokens("/*1Constructor1*/", { });
	ExpectTokens("/*;Constructor;*/", { });
	ExpectTokens("/*Constructor", { });
	ExpectTokens("/* Constructor ", { });
	ExpectTokens("/*1Constructor1", { });
	ExpectTokens("/*;Constructor;", { });
}
