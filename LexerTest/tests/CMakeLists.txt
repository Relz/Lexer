INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/LexerProject)

ADD_EXECUTABLE(LexerTest
		TestHelper.cpp
		TestHelper.h
		PlusTokenTest.cpp
		MinusTokenTest.cpp
		MultiplyTokenTest.cpp
		DivisionTokenTest.cpp
		AssignmentTokenTest.cpp
		PlusAssignmentTokenTest.cpp
		MinusAssignmentTokenTest.cpp
		MultiplyAssignmentTokenTest.cpp
		DivisionAssignmentTokenTest.cpp
		EquivalenceTokenTest.cpp
		NotEquivalenceTokenTest.cpp
		MoreOrEquivalenceTokenTest.cpp
		LessOrEquivalenceTokenTest.cpp
		MoreTokenTest.cpp
		LessTokenTest.cpp
		ClassTokenTest.cpp
		ExtendsTokenTest.cpp
		ImplementsTokenTest.cpp)

TARGET_LINK_LIBRARIES(LexerTest gtest gtest_main Lexer)
