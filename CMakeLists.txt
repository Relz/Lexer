CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(LexerLibrary)

SET(CMAKE_CXX_STANDARD 17)

SET(SOURCE_FILES
	NumberSystem/NumberSystem.h
	NumberSystem/NumberSystemExtensions/NumberSystemExtensions.cpp
	NumberSystem/NumberSystemExtensions/NumberSystemExtensions.h
	Token/TokenConstant/TokenConstant.cpp
	Token/TokenConstant/TokenConstant.h
	Token/Parenthesis/Parenthesis.cpp
	Token/Parenthesis/Parenthesis.h
	Token/TokenExtensions/TokenExtensions.cpp
	Token/TokenExtensions/TokenExtensions.h
	Token/TokenInformation/TokenInformation.cpp
	Token/TokenInformation/TokenInformation.h
	Token/Token.h
	Lexer.cpp
	Lexer.h)

ADD_LIBRARY(LexerLibrary SHARED ${SOURCE_FILES})

ADD_SUBDIRECTORY(InputLibrary)

TARGET_LINK_LIBRARIES(LexerLibrary InputLibrary)
