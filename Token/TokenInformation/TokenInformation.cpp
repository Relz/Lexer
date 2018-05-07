#include "TokenInformation.h"

TokenInformation::TokenInformation(Token token, StreamString const & tokenStreamString, std::string const & fileName)
	: m_token(token)
	, m_tokenStreamString(tokenStreamString)
	, m_fileName(fileName)
{}

Token TokenInformation::GetToken()
{
	return m_token;
}

StreamString const & TokenInformation::GetTokenStreamString()
{
	return m_tokenStreamString;
}

std::string const & TokenInformation::GetFileName()
{
	return m_fileName;
}

std::wstring TokenInformation::ToString() const
{
	return std::wstring(m_fileName.begin(), m_fileName.end()) + L"[" + std::to_wstring(m_tokenStreamString.position.GetLine()) + L", "
		+ std::to_wstring(m_tokenStreamString.position.GetColumn()) + L"]: \n" + L"\t" + L"String : "
		+ m_tokenStreamString.string + L"\n" + L"\t" + L"Type   : " + TokenExtensions::ToString(m_token) + L"\n";
}
