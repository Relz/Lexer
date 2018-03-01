SET(SOURCE_FILES
		Token.h
		Constant/Parenthesis.h
        Constant/Constant.h
        TokenInformation.h
		TokenExtensions.h)

ADD_LIBRARY(Token ${SOURCE_FILES})
SET_TARGET_PROPERTIES(Token PROPERTIES LINKER_LANGUAGE CXX)
