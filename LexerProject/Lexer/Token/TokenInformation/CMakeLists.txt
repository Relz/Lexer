SET(SOURCE_FILES
		TokenInformation.cpp
		TokenInformation.h)

ADD_LIBRARY(TokenInformation ${SOURCE_FILES})
SET_TARGET_PROPERTIES(TokenInformation PROPERTIES LINKER_LANGUAGE CXX)
