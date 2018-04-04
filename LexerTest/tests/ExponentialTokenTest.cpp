#include "Lexer/Token/Token.h"
#include "TestHelper.h"
#include "gtest/gtest.h"

using namespace std;

TEST(exponential_token, determining_if_stay_alone)
{
	ExpectTokens("1_E+1", { Token::EXPONENTIAL });
	ExpectTokens("1_E-1", { Token::EXPONENTIAL });
	ExpectTokens("1.1_E+1", { Token::EXPONENTIAL });
	ExpectTokens("1.1_E-1", { Token::EXPONENTIAL });
	ExpectTokens("2_1_E+1", { Token::EXPONENTIAL });
	ExpectTokens("2_1_E-1", { Token::EXPONENTIAL });
	ExpectTokens("2_1.0_E+1", { Token::EXPONENTIAL });
	ExpectTokens("2_1.0_E-1", { Token::EXPONENTIAL });
	ExpectTokens("16_F.A_E+1", { Token::EXPONENTIAL });
	ExpectTokens("16_F.A_E-1", { Token::EXPONENTIAL });
	ExpectTokens("16_F.0A_E+1", { Token::EXPONENTIAL });
	ExpectTokens("16_F.0A_E-1", { Token::EXPONENTIAL });

	ExpectTokens("1_E+1.1", { Token::EXPONENTIAL });
	ExpectTokens("1_E-1.1", { Token::EXPONENTIAL });
	ExpectTokens("1.1_E+1.1", { Token::EXPONENTIAL });
	ExpectTokens("1.1_E-1.1", { Token::EXPONENTIAL });
	ExpectTokens("2_1_E+1.1", { Token::EXPONENTIAL });
	ExpectTokens("2_1_E-1.1", { Token::EXPONENTIAL });
	ExpectTokens("2_1.0_E+1.1", { Token::EXPONENTIAL });
	ExpectTokens("2_1.0_E-1.1", { Token::EXPONENTIAL });
	ExpectTokens("16_F.A_E+1.1", { Token::EXPONENTIAL });
	ExpectTokens("16_F.A_E-1.1", { Token::EXPONENTIAL });
	ExpectTokens("16_F.0A_E+1.1", { Token::EXPONENTIAL });
	ExpectTokens("16_F.0A_E-1.1", { Token::EXPONENTIAL });
}

TEST(exponential_token, determining_if_stay_between_delimiters)
{
	ExpectTokens(" 1_E+1 ", { Token::EXPONENTIAL });
	ExpectTokens(";1_E+1;", { Token::SEMICOLON, Token::EXPONENTIAL, Token::SEMICOLON });
	ExpectTokens(" 2_1_E+3 ", { Token::EXPONENTIAL });
	ExpectTokens(";2_1_E+3;", { Token::SEMICOLON, Token::EXPONENTIAL, Token::SEMICOLON });
	ExpectTokens(" 16_F_E+1 ", { Token::EXPONENTIAL });
	ExpectTokens(";16_F_E+1;", { Token::SEMICOLON, Token::EXPONENTIAL, Token::SEMICOLON });

	ExpectTokens(" 1.1_E+1 ", { Token::EXPONENTIAL });
	ExpectTokens(";1.1_E+1;", { Token::SEMICOLON, Token::EXPONENTIAL, Token::SEMICOLON });
	ExpectTokens(" 2_1.1_E+3 ", { Token::EXPONENTIAL });
	ExpectTokens(";2_1.1_E+3;", { Token::SEMICOLON, Token::EXPONENTIAL, Token::SEMICOLON });
	ExpectTokens(" 16_F.A_E+1 ", { Token::EXPONENTIAL });
	ExpectTokens(";16_F.A_E+1;", { Token::SEMICOLON, Token::EXPONENTIAL, Token::SEMICOLON });

	ExpectTokens(" 1.1_E+1.1 ", { Token::EXPONENTIAL });
	ExpectTokens(";1.1_E+1.1;", { Token::SEMICOLON, Token::EXPONENTIAL, Token::SEMICOLON });
	ExpectTokens(" 2_1.1_E+3.1 ", { Token::EXPONENTIAL });
	ExpectTokens(";2_1.1_E+3.1;", { Token::SEMICOLON, Token::EXPONENTIAL, Token::SEMICOLON });
	ExpectTokens(" 16_F.A_E+1.1 ", { Token::EXPONENTIAL });
	ExpectTokens(";16_F.A_E+1.1;", { Token::SEMICOLON, Token::EXPONENTIAL, Token::SEMICOLON });
}

TEST(exponential_token, determining_if_stay_near_delimiter)
{
	ExpectTokens("1_E+1;", { Token::EXPONENTIAL, Token::SEMICOLON });
	ExpectTokens(";1_E+1", { Token::SEMICOLON, Token::EXPONENTIAL });
	ExpectTokens(" 2_1_E+1;", { Token::EXPONENTIAL, Token::SEMICOLON });
	ExpectTokens(";2_1_E+1", { Token::SEMICOLON, Token::EXPONENTIAL });
	ExpectTokens("16_F_E+1;", { Token::EXPONENTIAL, Token::SEMICOLON });
	ExpectTokens(";16_F_E+1", { Token::SEMICOLON, Token::EXPONENTIAL });

	ExpectTokens("1.1_E+1;", { Token::EXPONENTIAL, Token::SEMICOLON });
	ExpectTokens(";1.1_E+1", { Token::SEMICOLON, Token::EXPONENTIAL });
	ExpectTokens(" 2_1.1_E+1;", { Token::EXPONENTIAL, Token::SEMICOLON });
	ExpectTokens(";2_1.1_E+1", { Token::SEMICOLON, Token::EXPONENTIAL });
	ExpectTokens("16_F.A_E+1;", { Token::EXPONENTIAL, Token::SEMICOLON });
	ExpectTokens(";16_F.A_E+1", { Token::SEMICOLON, Token::EXPONENTIAL });
}

TEST(exponential_token, not_determining_if_no_underscore_before_exponent_character)
{
	ExpectTokens("1E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
	ExpectTokens("1E-1", { Token::UNKNOWN, Token::MINUS, Token::INTEGER });
	ExpectTokens("1.1E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
	ExpectTokens("1.1E-1", { Token::UNKNOWN, Token::MINUS, Token::INTEGER });
	ExpectTokens("2_1E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
	ExpectTokens("2_1E-1", { Token::UNKNOWN, Token::MINUS, Token::INTEGER });
	ExpectTokens("2_1.0E+1", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
	ExpectTokens("2_1.0E-1", { Token::UNKNOWN, Token::MINUS, Token::INTEGER });
	ExpectTokens("16_F.AE+1", { Token::FLOAT, Token::PLUS, Token::INTEGER });
	ExpectTokens("16_F.AE-1", { Token::FLOAT, Token::MINUS, Token::INTEGER });
	ExpectTokens("16_F.0AE+1", { Token::FLOAT, Token::PLUS, Token::INTEGER });
	ExpectTokens("16_F.0AE-1", { Token::FLOAT, Token::MINUS, Token::INTEGER });

	ExpectTokens(" 1E+1 ", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
	ExpectTokens(";1E+1;", { Token::SEMICOLON, Token::UNKNOWN, Token::PLUS, Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(" 2_1E+3 ", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
	ExpectTokens(";2_1E+3;", { Token::SEMICOLON, Token::UNKNOWN, Token::PLUS, Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(" 16_FE+1 ", { Token::INTEGER, Token::PLUS, Token::INTEGER });
	ExpectTokens(";16_FE+1;", { Token::SEMICOLON, Token::INTEGER, Token::PLUS, Token::INTEGER, Token::SEMICOLON });

	ExpectTokens(" 1.1E+1 ", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
	ExpectTokens(";1.1E+1;", { Token::SEMICOLON, Token::UNKNOWN, Token::PLUS, Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(" 2_1.1E+3 ", { Token::UNKNOWN, Token::PLUS, Token::INTEGER });
	ExpectTokens(";2_1.1E+3;", { Token::SEMICOLON, Token::UNKNOWN, Token::PLUS, Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(" 16_F.AE+1 ", { Token::FLOAT, Token::PLUS, Token::INTEGER });
	ExpectTokens(";16_F.AE+1;", { Token::SEMICOLON, Token::FLOAT, Token::PLUS, Token::INTEGER, Token::SEMICOLON });

	ExpectTokens("1E+1;", { Token::UNKNOWN, Token::PLUS, Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(";1E+1", { Token::SEMICOLON, Token::UNKNOWN, Token::PLUS, Token::INTEGER });
	ExpectTokens(" 2_1E+1;", { Token::UNKNOWN, Token::PLUS, Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(";2_1E+1", { Token::SEMICOLON, Token::UNKNOWN, Token::PLUS, Token::INTEGER });
	ExpectTokens("16_FE+1;", { Token::INTEGER, Token::PLUS, Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(";16_FE+1", { Token::SEMICOLON, Token::INTEGER, Token::PLUS, Token::INTEGER });

	ExpectTokens("1.1E+1;", { Token::UNKNOWN, Token::PLUS, Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(";1.1E+1", { Token::SEMICOLON, Token::UNKNOWN, Token::PLUS, Token::INTEGER });
	ExpectTokens(" 2_1.1E+1;", { Token::UNKNOWN, Token::PLUS, Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(";2_1.1E+1", { Token::SEMICOLON, Token::UNKNOWN, Token::PLUS, Token::INTEGER });
	ExpectTokens("16_F.AE+1;", { Token::FLOAT, Token::PLUS, Token::INTEGER, Token::SEMICOLON });
	ExpectTokens(";16_F.AE+1", { Token::SEMICOLON, Token::FLOAT, Token::PLUS, Token::INTEGER });
}

TEST(exponential_token, not_determining_if_not_completed)
{
	ExpectTokens("1_E+", { Token::UNKNOWN });
	ExpectTokens("1_E-", { Token::UNKNOWN });
	ExpectTokens("1.1_E+", { Token::UNKNOWN });
	ExpectTokens("1.1_E-", { Token::UNKNOWN });
	ExpectTokens("2_1_E+", { Token::UNKNOWN });
	ExpectTokens("2_1_E-", { Token::UNKNOWN });
	ExpectTokens("2_1.0_E+", { Token::UNKNOWN });
	ExpectTokens("2_1.0_E-", { Token::UNKNOWN });
	ExpectTokens("16_F.A_E+", { Token::UNKNOWN });
	ExpectTokens("16_F.A_E-", { Token::UNKNOWN });
	ExpectTokens("16_F.0A_E+", { Token::UNKNOWN });
	ExpectTokens("16_F.0A_E-", { Token::UNKNOWN });

	ExpectTokens("1_E", { Token::UNKNOWN });
	ExpectTokens("1.1_E", { Token::UNKNOWN });
	ExpectTokens("2_1_E", { Token::UNKNOWN });
	ExpectTokens("2_1.0_E", { Token::UNKNOWN });
	ExpectTokens("16_F.A_E", { Token::UNKNOWN });
	ExpectTokens("16_F.0A_E", { Token::UNKNOWN });

	ExpectTokens("1_", { Token::UNKNOWN });
	ExpectTokens("1.1_", { Token::UNKNOWN });
	ExpectTokens("2_1_", { Token::UNKNOWN });
	ExpectTokens("2_1.0_", { Token::UNKNOWN });
	ExpectTokens("16_F.A_", { Token::UNKNOWN });
	ExpectTokens("16_F.0A_", { Token::UNKNOWN });

	ExpectTokens("1_E+1.", { Token::UNKNOWN });
	ExpectTokens("1_E-1.", { Token::UNKNOWN });
	ExpectTokens("1.1_E+1.", { Token::UNKNOWN });
	ExpectTokens("1.1_E-1.", { Token::UNKNOWN });
	ExpectTokens("2_1_E+1.", { Token::UNKNOWN });
	ExpectTokens("2_1_E-1.", { Token::UNKNOWN });
	ExpectTokens("2_1.0_E+1.", { Token::UNKNOWN });
	ExpectTokens("2_1.0_E-1.", { Token::UNKNOWN });
	ExpectTokens("16_F.A_E+1.", { Token::UNKNOWN });
	ExpectTokens("16_F.A_E-1.", { Token::UNKNOWN });
	ExpectTokens("16_F.0A_E+1.", { Token::UNKNOWN });
	ExpectTokens("16_F.0A_E-1.", { Token::UNKNOWN });
}

TEST(exponential_token, not_determining_if_part_of_string_literal)
{
	ExpectTokens("\"1_E+1\"", { Token::STRING_LITERAL });
	ExpectTokens("\" 1_E+1 \"", { Token::STRING_LITERAL });
	ExpectTokens("\";1_E+1;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"2_1_E+1\"", { Token::STRING_LITERAL });
	ExpectTokens("\" 2_1_E+1 \"", { Token::STRING_LITERAL });
	ExpectTokens("\";2_1_E+1;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"16_F_E+1\"", { Token::STRING_LITERAL });
	ExpectTokens("\" 16_F_E+1 \"", { Token::STRING_LITERAL });
	ExpectTokens("\";16_F_E+1;\"", { Token::STRING_LITERAL });

	ExpectTokens("\"1.1_E+1\"", { Token::STRING_LITERAL });
	ExpectTokens("\" 1.1_E+1 \"", { Token::STRING_LITERAL });
	ExpectTokens("\";1.1_E+1;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"2_1.1_E+1\"", { Token::STRING_LITERAL });
	ExpectTokens("\" 2_1.1_E+1 \"", { Token::STRING_LITERAL });
	ExpectTokens("\";2_1.1_E+1;\"", { Token::STRING_LITERAL });
	ExpectTokens("\"16_F.A_E+1\"", { Token::STRING_LITERAL });
	ExpectTokens("\" 16_F.A_E+1 \"", { Token::STRING_LITERAL });
	ExpectTokens("\";16_F.A_E+1;\"", { Token::STRING_LITERAL });
}

TEST(exponential_token, not_determining_if_part_of_comment)
{
	ExpectTokens("//1_E+1", { });
	ExpectTokens("// 1_E+1 ", { });
	ExpectTokens("//;1_E+1;", { });
	ExpectTokens("/*1_E+1*/", { });
	ExpectTokens("/* 1_E+1 */", { });
	ExpectTokens("/*1_E+1*/", { });
	ExpectTokens("/*;1_E+1;*/", { });
	ExpectTokens("/*1_E+1", { });
	ExpectTokens("/* 1_E+1 ", { });
	ExpectTokens("/*1_E+1", { });
	ExpectTokens("/*;1_E+1;", { });

	ExpectTokens("//2_1_E+1", { });
	ExpectTokens("// 2_1_E+1 ", { });
	ExpectTokens("//;2_1_E+1;", { });
	ExpectTokens("/*2_1_E+1*/", { });
	ExpectTokens("/* 2_1_E+1 */", { });
	ExpectTokens("/*2_1_E+1*/", { });
	ExpectTokens("/*;2_1_E+1;*/", { });
	ExpectTokens("/*2_1_E+1", { });
	ExpectTokens("/* 2_1_E+1 ", { });
	ExpectTokens("/*2_1_E+1", { });
	ExpectTokens("/*;2_1_E+1;", { });

	ExpectTokens("//16_F_E+1", { });
	ExpectTokens("// 16_F_E+1 ", { });
	ExpectTokens("//;16_F_E+1;", { });
	ExpectTokens("/*16_F_E+1*/", { });
	ExpectTokens("/* 16_F_E+1 */", { });
	ExpectTokens("/*16_F_E+1*/", { });
	ExpectTokens("/*;16_F_E+1;*/", { });
	ExpectTokens("/*16_F_E+1", { });
	ExpectTokens("/* 16_F_E+1 ", { });
	ExpectTokens("/*16_F_E+1", { });
	ExpectTokens("/*;16_F_E+1;", { });

	ExpectTokens("//1.1_E+1", {});
	ExpectTokens("// 1.1_E+1 ", {});
	ExpectTokens("//;1.1_E+1;", {});
	ExpectTokens("/*1.1_E+1*/", {});
	ExpectTokens("/* 1.1_E+1 */", {});
	ExpectTokens("/*1.1_E+1*/", {});
	ExpectTokens("/*;1.1_E+1;*/", {});
	ExpectTokens("/*1.1_E+1", {});
	ExpectTokens("/* 1.1_E+1 ", {});
	ExpectTokens("/*1.1_E+1", {});
	ExpectTokens("/*;1.1_E+1;", {});

	ExpectTokens("//2_1.1_E+1", {});
	ExpectTokens("// 2_1.1_E+1 ", {});
	ExpectTokens("//;2_1.1_E+1;", {});
	ExpectTokens("/*2_1.1_E+1*/", {});
	ExpectTokens("/* 2_1.1_E+1 */", {});
	ExpectTokens("/*2_1.1_E+1*/", {});
	ExpectTokens("/*;2_1.1_E+1;*/", {});
	ExpectTokens("/*2_1.1_E+1", {});
	ExpectTokens("/* 2_1.1_E+1 ", {});
	ExpectTokens("/*2_1.1_E+1", {});
	ExpectTokens("/*;2_1.1_E+1;", {});

	ExpectTokens("//16_F.A_E+1", {});
	ExpectTokens("// 16_F.A_E+1 ", {});
	ExpectTokens("//;16_F.A_E+1;", {});
	ExpectTokens("/*16_F.A_E+1*/", {});
	ExpectTokens("/* 16_F.A_E+1 */", {});
	ExpectTokens("/*16_F.A_E+1*/", {});
	ExpectTokens("/*;16_F.A_E+1;*/", {});
	ExpectTokens("/*16_F.A_E+1", {});
	ExpectTokens("/* 16_F.A_E+1 ", {});
	ExpectTokens("/*16_F.A_E+1", {});
	ExpectTokens("/*;16_F.A_E+1;", {});
}
