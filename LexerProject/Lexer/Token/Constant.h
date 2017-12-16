#ifndef TOKEN_CONSTANT_H
#define TOKEN_CONSTANT_H

static class Operator
{
public:
	static const char PLUS = '+';
	static const char MINUS = '-';
	static const char MULTIPLY = '*';
	static const char DIVISION = '/';
};

static class Keyword
{
public:
	static const std::string CLASS = "class";
	static const std::string EXTENDS = "extends";
	static const std::string IMPLEMENTS = "emplements";
	static const std::string CONSTRUCTOR = "Constructor";
	static const std::string NOT_INITIALIZED = "NULL";
	static const std::string PRIVATE = "private";
	static const std::string PUBLIC = "public";
	static const std::string GET = "get";
	static const std::string SET = "set";
	static const std::string FOR = "for";
	static const std::string WHILE = "while";
	static const std::string DO = "do";
	static const std::string RETURN = "return";
};

static class CoreType
{
public:
	static const std::string INTEGER = "Integer";
	static const std::string FLOAT = "Float";
	static const std::string DOUBLE = "Double";
	static const std::string STRING = "String";
	static const std::string ARRAY = "Array";
};

#endif //TOKEN_CONSTANT_H
