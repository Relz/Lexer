#ifndef TOKEN_TOKENINFO_H
#define TOKEN_TOKENINFO_H

#include "Token.h"

using namespace std;

class TokenInformation
{
public:
	TokenInformation(Token token, string const& tokenString, StreamPosition const& position)
			: m_token(token)
			, m_tokenString(tokenString)
			, m_position(position)
	{
	}

	void SetFileName(string const& fileName)
	{
		m_fileName = fileName;
	}

	string ToString()
	{
		return m_fileName + "[" + to_string(m_position.GetLine()) + ", " + to_string(m_position.GetColumn()) + "]: \n"
			   + "\t" + "String : " + m_tokenString + "\n"
			   + "\t" + "Type   : " + TokenExtensions::ToString(m_token) + "\n";
	}

private:
	const Token m_token;
	const string m_tokenString;
	string m_fileName;
	const StreamPosition m_position;
};


#endif //PROJECT_TOKENINFO_H
