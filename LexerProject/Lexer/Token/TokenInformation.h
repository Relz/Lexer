#ifndef TOKEN_TOKENINFO_H
#define TOKEN_TOKENINFO_H

#include "Token.h"
#include "../InputSolution/Input/StreamString.h"
#include "TokenExtensions.h"

class TokenInformation
{
public:
	TokenInformation() = default;

	TokenInformation(Token token, StreamString const& tokenStreamString, std::string const& fileName)
		: m_token(token)
		, m_tokenStreamString(tokenStreamString)
		, m_fileName(fileName)
	{
	}

	std::string ToString() const
	{
		return m_fileName + "["
			+ std::to_string(m_tokenStreamString.position.GetLine())
			+ ", "
			+ std::to_string(m_tokenStreamString.position.GetColumn())
			+ "]: \n"
			+ "\t" + "String : " + m_tokenStreamString.string + "\n"
			+ "\t" + "Type   : " + TokenExtensions::ToString(m_token) + "\n";
	}
private:
	Token m_token;
	StreamString m_tokenStreamString;
	std::string m_fileName;
};


#endif //PROJECT_TOKENINFO_H
