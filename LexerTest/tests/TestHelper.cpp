#include "TestHelper.h"

void ExpectTokens(string const & string, vector<Token> const & expectedTokens)
{
	stringstream stringStream(string);
	Lexer lexer(stringStream);
	size_t i = 0;
	TokenInformation tokenInformation;
	while (lexer.GetNextTokenInformation(tokenInformation))
	{
		EXPECT_LT(i, expectedTokens.size());
		EXPECT_EQ(
			TokenExtensions::ToString(tokenInformation.GetToken()), TokenExtensions::ToString(expectedTokens.at(i)));
		++i;
	}
	EXPECT_EQ(i, expectedTokens.size());
}
