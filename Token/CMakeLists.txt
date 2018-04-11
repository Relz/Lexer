SET(SOURCE_FILES
		Token.h
		Parenthesis/Parenthesis.h
		TokenConstant/TokenConstant.h)

ADD_LIBRARY(Token ${SOURCE_FILES})

ADD_SUBDIRECTORY(Parenthesis)
ADD_SUBDIRECTORY(TokenConstant)
ADD_SUBDIRECTORY(TokenExtensions)
ADD_SUBDIRECTORY(TokenInformation)

TARGET_LINK_LIBRARIES(Token Parenthesis TokenConstant TokenExtensions TokenInformation)
