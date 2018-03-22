SET(SOURCE_FILES
		Token.h
		Constant/Parenthesis.h
		Constant/Constant.h)

ADD_LIBRARY(Token ${SOURCE_FILES})
SET_TARGET_PROPERTIES(Token PROPERTIES LINKER_LANGUAGE CXX)

ADD_SUBDIRECTORY(TokenExtensions)
ADD_SUBDIRECTORY(TokenInformation)

TARGET_LINK_LIBRARIES(Token TokenExtensions TokenInformation)
