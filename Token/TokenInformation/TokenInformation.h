#ifndef TOKEN_TOKENINFORMATION_H
#define TOKEN_TOKENINFORMATION_H

#include "../../InputSolution/Input/StreamString.h"
#include "../Token.h"
#include "../TokenExtensions/TokenExtensions.h"
#include <string>

class TokenInformation
{
public:
	explicit TokenInformation() = default;
	explicit TokenInformation(Token token, StreamString const & tokenStreamString, std::string const & fileName = "");
	Token GetToken();
	StreamString const & GetTokenStreamString();
	std::string const & GetFileName();
	std::string ToString() const;

private:
	Token m_token = Token::UNKNOWN;
	StreamString m_tokenStreamString;
	std::string m_fileName;
};

#endif //TOKEN_TOKENINFORMATION_H
