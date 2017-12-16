SET(SOURCE_FILES
        Lexer.cpp
        Lexer.h
		Constant.h
		Token/TokenUtils.cpp
		Token/TokenUtils.h
		Token/Token.h
		Token/Rule/Rule.cpp
		Token/Rule/Rule.h
		Token/Constant.h
)

ADD_LIBRARY(Lexer ${SOURCE_FILES})

ADD_SUBDIRECTORY(Input)
