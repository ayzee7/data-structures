#include "gtest.h"
#include "Stack.h"

TEST(stack, can_create_stack) {
	ASSERT_NO_THROW(Stack<int> s);
}

TEST(stack, can_push_element) {
	Stack<int> s;
	s.push(1);
	ASSERT_EQ(s.top(), 1);
}

TEST(stack, can_return_top) {
	Stack<int> s;
	s.push(1);
	s.push(2);
	ASSERT_EQ(s.top(), 2);
}

TEST(stack, can_pop_element) {
	Stack<int> s;
	s.push(1);
	int top = s.top();
	s.push(2);
	s.pop();
	ASSERT_EQ(s.top(), top);
}

TEST(stack, can_return_size) {
	Stack<int> s;
	s.push(1);
	s.push(2);
	ASSERT_EQ(s.size(), 2);
}

TEST(stack, can_clear_stack) {
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.clear();
	ASSERT_EQ(s.size(), 0);
}

TEST(stack, empty_stack_returns_true) {
	Stack<int> s;
	ASSERT_EQ(s.empty(), true);
}

TEST(stack, filled_stack_returns_false) {
	Stack<int> s;
	s.push(1);
	ASSERT_EQ(s.empty(), false);
}