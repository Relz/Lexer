#ifndef TOKEN_TOKENINFO_H
#define TOKEN_TOKENINFO_H

#include "Token.h"

class TokenInfo
{
public:
	TokenInfo(Token token, const std::string & tokenString, Position position)
			: _token(token)
			, _tokenString(tokenString)
			, _position(position)
	{
	}

	void SetFileName(const std::string & fileName)
	{
		_fileName = fileName;
	}

	std::string ToString()
	{
		return _fileName + "[" + std::to_string(_position.line) + ", " + std::to_string(_position.column) + "]: \n"
			   + "\t" + "String : " + _tokenString + "\n"
			   + "\t" + "Type   : " + TokenExtensions::ToString(_token) + "\n";
	}

private:
	const Token _token;
	const std::string _tokenString;
	std::string _fileName;
	const Position _position;
};


#endif //PROJECT_TOKENINFO_H
