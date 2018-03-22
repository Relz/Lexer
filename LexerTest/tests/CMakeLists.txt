INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/LexerProject)

ADD_EXECUTABLE(LexerTest
		TestHelper.cpp
		TestHelper.h
		PlusTokenTest.cpp
		MinusTokenTest.cpp
		MultiplyTokenTest.cpp
		DivisionTokenTest.cpp)

TARGET_LINK_LIBRARIES(LexerTest gtest gtest_main Lexer)
