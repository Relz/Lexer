#include "gtest/gtest.h"
#include <string>
#include <sstream>

#include "TestHelper.h"

using namespace std;

TEST(plus_token, determining_if_stay_alone)
{
	test("+", { Token::PLUS });
}

TEST(plus_token, determining_if_stay_between_delimiters)
{
	test(" + ", { Token::PLUS });
	test(";+;", { Token::SEMICOLON, Token::PLUS, Token::SEMICOLON });
}

TEST(plus_token, determining_if_stay_near_delimiter)
{
	test("+;", { Token::PLUS, Token::SEMICOLON });
	test(";+", { Token::SEMICOLON, Token::PLUS });
}

TEST(plus_token, determining_if_between_numbers)
{
	test("1+1", { Token::INTEGER, Token::PLUS, Token::INTEGER });
	test("1+1.1", { Token::INTEGER, Token::PLUS, Token::FLOAT });
	test("1.1+1", { Token::FLOAT, Token::PLUS, Token::INTEGER });
	test("1.1+1.1", { Token::FLOAT, Token::PLUS, Token::FLOAT });
	test("1E+1+1", { Token::EXPONENTIAL, Token::PLUS, Token::INTEGER });
	test("1+1E+1", { Token::INTEGER, Token::PLUS, Token::EXPONENTIAL });
	test("1.1E+1+1", { Token::EXPONENTIAL, Token::PLUS, Token::INTEGER });
	test("1+1.1E+1", { Token::INTEGER, Token::PLUS, Token::EXPONENTIAL });
	test("1E+1.1+1", { Token::EXPONENTIAL, Token::PLUS, Token::INTEGER });
	test("1+1E+1.1", { Token::INTEGER, Token::PLUS, Token::EXPONENTIAL });
	test("1E+1+1.1", { Token::EXPONENTIAL, Token::PLUS, Token::FLOAT });
	test("1.1+1E+1", { Token::FLOAT, Token::PLUS, Token::EXPONENTIAL });
	test("1E+1+1E+1", { Token::EXPONENTIAL, Token::PLUS, Token::EXPONENTIAL });
}
