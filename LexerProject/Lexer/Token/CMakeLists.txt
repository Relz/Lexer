SET(SOURCE_FILES
        Token.h
        TokenUtils.h
        Rule.h
        Constant/Parenthesis.h
        Constant/Constant.h
        TokenInformation.h
        )

ADD_LIBRARY(Token ${SOURCE_FILES})
SET_TARGET_PROPERTIES(Token PROPERTIES LINKER_LANGUAGE CXX)
