PROJECT(LexerProject)

SET(CMAKE_CXX_STANDARD 11)
ADD_DEFINITIONS(-std=c++11)

SET_SOURCE_FILES_PROPERTIES(LexerProject/stdafx.cpp
        PROPERTIES
        COMPILE_FLAGS "-include ../LexerProject/stdafx.h")

SET(SOURCE_FILES main.cpp Constant.h)
ADD_EXECUTABLE(LexerProject ${SOURCE_FILES})

ADD_SUBDIRECTORY(Lexer)

TARGET_LINK_LIBRARIES(LexerProject Lexer)
