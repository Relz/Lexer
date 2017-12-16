INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

ADD_EXECUTABLE(LexerTest
		ConstructorTest.cpp
		)

TARGET_LINK_LIBRARIES(LexerTest gtest gtest_main)
TARGET_LINK_LIBRARIES(LexerTest Lexer)
