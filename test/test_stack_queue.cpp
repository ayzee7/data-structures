#include "gtest.h"
#include "Stack.h"
#include "Queue.h"

//	Stack
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

TEST(stack, cant_pop_element_from_empty_stack) {
	Stack<int> s;
	ASSERT_ANY_THROW(s.pop());
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
	ASSERT_TRUE(s.empty());
}

TEST(stack, filled_stack_returns_false) {
	Stack<int> s;
	s.push(1);
	ASSERT_FALSE(s.empty());
}


//	Queue
TEST(queue, can_create_queue) {
	ASSERT_NO_THROW(Queue<int> q);
}

TEST(queue, can_create_copied_queue) {
	Queue<int> q;
	ASSERT_NO_THROW(Queue<int> q1(q));
}

TEST(queue, can_assign_queue_to_another) {
	Queue<int> q;
	Queue<int> q1 = q;
	ASSERT_EQ(q, q1);
}

TEST(queue, can_push_element) {
	Queue<int> q;
	ASSERT_NO_THROW(q.push(1));
}

TEST(queue, can_get_size) {
	Queue<int> q;
	ASSERT_EQ(q.size(), 0);
}

TEST(queue, push_changes_queue_size) {
	Queue<int> q;
	int size = q.size();
	q.push(1);
	ASSERT_NE(size, q.size());
}

TEST(queue, empty_queue_returns_true) {
	Queue<int> q;
	ASSERT_TRUE(q.isEmpty());
}

TEST(queue, filled_queue_returns_false) {
	Queue<int> q;
	q.push(1);
	ASSERT_FALSE(q.isEmpty());
}

TEST(queue, full_queue_returns_true) {
	Queue<int> q;
	for (int i = 0; i < 10; i++) {
		q.push(1);
	}
	ASSERT_TRUE(q.isFull());
}

TEST(queue, not_full_queue_returns_false) {
	Queue<int> q;
	for (int i = 0; i < 9; i++) {
		q.push(1);
	}
	ASSERT_FALSE(q.isFull());
}

TEST(queue, queue_repacks_when_full) {
	Queue<int> q;
	//	Queue allocates enough memory for 10 elements
	for (int i = 0; i < 10; i++) {
		q.push(1);
	}
	//	Pushing 11th element
	q.push(1);
	//	Checking if queue is full (repacking occured)
	ASSERT_FALSE(q.isFull());
}

TEST(queue, can_pop_element) {
	Queue<int> q;
	q.push(1);
	q.pop();
	ASSERT_TRUE(q.isEmpty());
}

TEST(queue, can_push_element_in_place_of_popped_one) {
	Queue<int> q;
	//	Filling queue
	for (int i = 0; i < 10; i++) {
		q.push(1);
	}
	q.pop();
	q.push(1);
	//	Checking that pushed element was placed in front (repacking never occured)
	ASSERT_TRUE(q.isFull());
}

TEST(queue, pop_works_in_circular_principle) {
	Queue<int> q;
	// Filling queue
	for (int i = 0; i < 10; i++) {
		q.push(1);
	}
	//	Popping all elements
	for (int i = 0; i < 10; i++) {
		q.pop();
	}
	//	Pushing element in front and trying to pop it
	q.push(1);
	q.pop();
	ASSERT_TRUE(q.isEmpty());
}

TEST(queue, cant_pop_element_from_empty_queue) {
	Queue<int> q;
	ASSERT_ANY_THROW(q.pop());
}

TEST(queue, can_clear_queue) {
	Queue<int> q;
	for (int i = 0; i < 10; i++) {
		q.push(1);
	}
	q.clear();
	ASSERT_TRUE(q.isEmpty());
}