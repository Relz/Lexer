SET(SOURCE_FILES
		NumberSystem.h
		NumberSystemExtensions/NumberSystemExtensions.cpp
		NumberSystemExtensions/NumberSystemExtensions.h)

ADD_LIBRARY(NumberSystem ${SOURCE_FILES})
SET_TARGET_PROPERTIES(NumberSystem PROPERTIES LINKER_LANGUAGE CXX)
