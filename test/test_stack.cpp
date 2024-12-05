#include "stack.h"
#include "term.h"
#include <gtest.h>
#include <vector>

TEST(stack, EmptyStackSizeIs0) {
	Stack<int, std::vector> intStack;
	ASSERT_EQ(intStack.size(), 0);
}

TEST(stack, EmptyStackIsEmpty) {
	Stack<int, std::vector> s;
	EXPECT_TRUE(s.empty());
}

TEST(stack, ThrowsWhenTopToEmptyStack) {
	Stack<int, std::vector> s;
	ASSERT_ANY_THROW(s.top());
}

TEST(stack, GotTopSuccessfully) {
	Stack<int, std::vector> s;
	s.push(5);
	ASSERT_EQ(s.top(), 5);
}

TEST(stack, push) {
	Stack<int, std::vector> s;
	s.push(1);
	EXPECT_EQ(s.top(), 1);
	s.push(2);
	EXPECT_EQ(s.top(), 2);
	s.push(3);
	EXPECT_EQ(s.top(), 3);
}

TEST(stack, pop) {
	Stack<int, std::vector> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	EXPECT_EQ(s.top(), 2);
	EXPECT_EQ(s.size(), 2);
}

TEST(stack, push_pop_push) {
	Stack<int, std::vector> s;
	s.push(1);
	s.push(2);
	s.pop();
	s.push(3);
	EXPECT_EQ(s.top(), 3);
}

TEST(translator, stuff) {
	//std::string meow;
	std::cout << "print your thing: ";
	//std::cin >> meow;
	//std::getline(std::cin, meow);
	Translator thing("3+5*2");
	thing.everything();
	EXPECT_EQ(1, 1);
}