SET(SOURCE_FILES
		Lexer.h
		Constant.h
		NumberSystem/NumberSystem.h NumberSystem/NumberSystemExtensions.h)

ADD_LIBRARY(Lexer ${SOURCE_FILES})
SET_TARGET_PROPERTIES(Lexer PROPERTIES LINKER_LANGUAGE CXX)

ADD_SUBDIRECTORY(InputSolution)
ADD_SUBDIRECTORY(Token)
