INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/LexerProject)

ADD_EXECUTABLE(LexerTest
		PlusTokenTest.cpp
		MinusTokenTest.cpp
		TestHelper.cpp TestHelper.h)

TARGET_LINK_LIBRARIES(LexerTest gtest gtest_main Lexer)
