SET(SOURCE_FILES
	NumberSystem.h)

ADD_LIBRARY(NumberSystem ${SOURCE_FILES})

ADD_SUBDIRECTORY(NumberSystemExtensions)

TARGET_LINK_LIBRARIES(NumberSystem NumberSystemExtensions)
