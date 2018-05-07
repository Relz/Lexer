#include "TokenConstant.h"

std::wstring const TokenConstant::Comment::BLOCK_BEGINNING = L"/*";
std::wstring const TokenConstant::Comment::BLOCK_ENDING = L"*/";
std::wstring const TokenConstant::Comment::LINE = L"//";

std::wstring const TokenConstant::Operator::Arithmetic::DIVISION = L"/";
std::wstring const TokenConstant::Operator::Arithmetic::MINUS = L"-";
wchar_t const TokenConstant::Operator::Arithmetic::MINUS_CHARACTER = L'-';
std::wstring const TokenConstant::Operator::Arithmetic::MULTIPLY = L"*";
std::wstring const TokenConstant::Operator::Arithmetic::PLUS = L"+";
wchar_t const TokenConstant::Operator::Arithmetic::PLUS_CHARACTER = L'+';

std::wstring const TokenConstant::Operator::Assignment::ASSIGNMENT = L"=";
std::wstring const TokenConstant::Operator::Assignment::DIVISION_ASSIGNMENT = L"/=";
std::wstring const TokenConstant::Operator::Assignment::MINUS_ASSIGNMENT = L"-=";
std::wstring const TokenConstant::Operator::Assignment::MULTIPLY_ASSIGNMENT = L"*=";
std::wstring const TokenConstant::Operator::Assignment::PLUS_ASSIGNMENT = L"+=";

std::wstring const TokenConstant::Operator::Comparison::EQUIVALENCE = L"==";
std::wstring const TokenConstant::Operator::Comparison::NOT_EQUIVALENCE = L"!=";
std::wstring const TokenConstant::Operator::Comparison::MORE_OR_EQUIVALENCE = L">=";
std::wstring const TokenConstant::Operator::Comparison::LESS_OR_EQUIVALENCE = L"<=";
std::wstring const TokenConstant::Operator::Comparison::MORE = L">";
std::wstring const TokenConstant::Operator::Comparison::LESS = L"<";

std::wstring const TokenConstant::Keyword::CLASS = L"class";
std::wstring const TokenConstant::Keyword::CONSTRUCTOR = L"Constructor";
std::wstring const TokenConstant::Keyword::DO = L"do";
std::wstring const TokenConstant::Keyword::EXTENDS = L"extends";
std::wstring const TokenConstant::Keyword::FOR = L"for";
std::wstring const TokenConstant::Keyword::GET = L"get";
std::wstring const TokenConstant::Keyword::IMPLEMENTS = L"implements";
std::wstring const TokenConstant::Keyword::NOT_INITIALIZED = L"NULL";
std::wstring const TokenConstant::Keyword::PRIVATE = L"private";
std::wstring const TokenConstant::Keyword::PUBLIC = L"public";
std::wstring const TokenConstant::Keyword::RETURN = L"return";
std::wstring const TokenConstant::Keyword::SET = L"set";
std::wstring const TokenConstant::Keyword::WHILE = L"while";
std::wstring const TokenConstant::Keyword::IF = L"if";
std::wstring const TokenConstant::Keyword::ELSE = L"else";

std::wstring const TokenConstant::CoreType::Number::DOUBLE = L"Double";
std::wstring const TokenConstant::CoreType::Number::FLOAT = L"Float";
std::wstring const TokenConstant::CoreType::Number::INTEGER = L"Integer";

std::wstring const TokenConstant::CoreType::Complex::ARRAY = L"Array";
std::wstring const TokenConstant::CoreType::Complex::STRING = L"String";

std::wstring const TokenConstant::CoreType::VOID = L"Void";

std::wstring const TokenConstant::Separator::DOT = L".";
wchar_t const TokenConstant::Separator::DOT_CHARACTER = L'.';
std::wstring const TokenConstant::Separator::COLON = L":";
std::wstring const TokenConstant::Separator::COMMA = L",";
std::wstring const TokenConstant::Separator::SEMICOLON = L";";
wchar_t const TokenConstant::Separator::EXPONENT_CHARACTER = L'E';
std::wstring const TokenConstant::Separator::SPACE = L" ";
std::wstring const TokenConstant::Separator::TAB = L"\t";
std::wstring const TokenConstant::Separator::END_OF_LINE_LF = L"\n";
std::wstring const TokenConstant::Separator::END_OF_LINE_CR = L"\r";
wchar_t const TokenConstant::Separator::UNDERSCORE_CHARACTER = L'_';

Parenthesis const TokenConstant::Parentheses::CURLY_BRACKET = { L"{", L"}" };
Parenthesis const TokenConstant::Parentheses::ROUND_BRACKET = { L"(", L")" };
Parenthesis const TokenConstant::Parentheses::SQUARE_BRACKET = { L"[", L"]" };
wchar_t const TokenConstant::Parentheses::QUOTE_CHARACTER = L'\'';
std::wstring const TokenConstant::Parentheses::QUOTE_STRING = L"'";
wchar_t const TokenConstant::Parentheses::DOUBLE_QUOTE_CHARACTER = L'"';
std::wstring const TokenConstant::Parentheses::DOUBLE_QUOTE_STRING = L"\"";

std::wstring const TokenConstant::Name::UNKNOWN = L"Unknown";

std::wstring const TokenConstant::Name::Operator::Arithmetic::DIVISION = L"Division";
std::wstring const TokenConstant::Name::Operator::Arithmetic::MINUS = L"Minus";
std::wstring const TokenConstant::Name::Operator::Arithmetic::MULTIPLY = L"Multiply";
std::wstring const TokenConstant::Name::Operator::Arithmetic::PLUS = L"Plus";

std::wstring const TokenConstant::Name::Operator::Assignment::ASSIGNMENT = L"Assignment";
std::wstring const TokenConstant::Name::Operator::Assignment::DIVISION_ASSIGNMENT = L"Division assignment";
std::wstring const TokenConstant::Name::Operator::Assignment::MINUS_ASSIGNMENT = L"Minus assignment";
std::wstring const TokenConstant::Name::Operator::Assignment::MULTIPLY_ASSIGNMENT = L"Multiply assignment";
std::wstring const TokenConstant::Name::Operator::Assignment::PLUS_ASSIGNMENT = L"Plus assignment";

std::wstring const TokenConstant::Name::Operator::Comparison::EQUIVALENCE = L"Equivalence";
std::wstring const TokenConstant::Name::Operator::Comparison::NOT_EQUIVALENCE = L"Not equivalence";
std::wstring const TokenConstant::Name::Operator::Comparison::MORE_OR_EQUIVALENCE = L"More or equal";
std::wstring const TokenConstant::Name::Operator::Comparison::LESS_OR_EQUIVALENCE = L"Less or equal";
std::wstring const TokenConstant::Name::Operator::Comparison::MORE = L"More";
std::wstring const TokenConstant::Name::Operator::Comparison::LESS = L"Less";

std::wstring const TokenConstant::Name::Keyword::CLASS = L"Class keyword";
std::wstring const TokenConstant::Name::Keyword::CONSTRUCTOR = L"Constructor keyword";
std::wstring const TokenConstant::Name::Keyword::DO = L"Do keyword";
std::wstring const TokenConstant::Name::Keyword::EXTENDS = L"Extends keyword";
std::wstring const TokenConstant::Name::Keyword::FOR = L"For keyword";
std::wstring const TokenConstant::Name::Keyword::GET = L"Get keyword";
std::wstring const TokenConstant::Name::Keyword::IMPLEMENTS = L"Implements keyword";
std::wstring const TokenConstant::Name::Keyword::NOT_INITIALIZED = L"NULL keyword";
std::wstring const TokenConstant::Name::Keyword::PRIVATE = L"Private keyword";
std::wstring const TokenConstant::Name::Keyword::PUBLIC = L"Public keyword";
std::wstring const TokenConstant::Name::Keyword::RETURN = L"Return keyword";
std::wstring const TokenConstant::Name::Keyword::SET = L"Set keyword";
std::wstring const TokenConstant::Name::Keyword::WHILE = L"While keyword";
std::wstring const TokenConstant::Name::Keyword::IF = L"If keyword";
std::wstring const TokenConstant::Name::Keyword::ELSE = L"Else keyword";

std::wstring const TokenConstant::Name::INTEGER = L"Integer";
std::wstring const TokenConstant::Name::FLOAT = L"Float";
std::wstring const TokenConstant::Name::EXPONENTIAL = L"Exponential";

std::wstring const TokenConstant::Name::Separator::DOT = L"Dot";
std::wstring const TokenConstant::Name::Separator::COLON = L"Colon";
std::wstring const TokenConstant::Name::Separator::COMMA = L"Comma";
std::wstring const TokenConstant::Name::Separator::SEMICOLON = L"Semicolon";

std::wstring const TokenConstant::Name::Parentheses::CURLY_BRACKET_LEFT = L"Left curly bracket";
std::wstring const TokenConstant::Name::Parentheses::CURLY_BRACKET_RIGHT = L"Right curly bracket";
std::wstring const TokenConstant::Name::Parentheses::ROUND_BRACKET_LEFT = L"Left round bracket";
std::wstring const TokenConstant::Name::Parentheses::ROUND_BRACKET_RIGHT = L"Right round bracket";
std::wstring const TokenConstant::Name::Parentheses::SQUARE_BRACKET_LEFT = L"Left square bracket";
std::wstring const TokenConstant::Name::Parentheses::SQUARE_BRACKET_RIGHT = L"Right square bracket";

std::wstring const TokenConstant::Name::TYPE = L"Type";
std::wstring const TokenConstant::Name::IDENTIFIER = L"Identifier";
std::wstring const TokenConstant::Name::STRING_LITERAL = L"String literal";
std::wstring const TokenConstant::Name::CHARACTER_LITERAL = L"Character literal";
std::wstring const TokenConstant::Name::LINE_COMMENT = L"Line comment";
std::wstring const TokenConstant::Name::BLOCK_COMMENT = L"Block comment";

std::wregex const TokenConstant::Regex::IDENTIFIER(L"[_a-zA-Z][_a-zA-Z0-9]*");
