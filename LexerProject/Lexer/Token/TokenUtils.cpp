#include "TokenUtils.h"

Token TokenUtils::DetermineTokenFromString(const std::string & tokenString)
{
	if (tokenString.empty())
	{
		return Token::UNKNOWN;
	}

	char firstChar = tokenString.at(0);
	if (Rule::IsLetter(firstChar))
	{
		if (!IsLetterOrDigitSequence(tokenString))
		{
			return Token::UNKNOWN;
		}
		try
		{
			return _stringsToKeywords.at(tokenString);
		}
		catch (std::out_of_range & e)
		{}

	}
	else if (Rule::IsDigit(firstChar))
	{

	}
	try
	{
		return _charsToOperatorTokens.at(firstChar);
	}
	catch (std::out_of_range & e)
	{}
	// TODO: Comments
}

bool TokenUtils::IsLetterOrDigitSequence(const std::string & tokenString)
{
	bool result = true;
	for (size_t i = 1; i < tokenString.length(); ++i)
	{
		if (!Rule::IsLetter(tokenString.at(i)) && !Rule::IsDigit(tokenString.at(i)))
		{
			result = false;
			break;
		}
	}

	return result;
}
