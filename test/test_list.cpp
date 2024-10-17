#include "gtest.h"
#include "List.h"

//	Node tests

TEST(node, can_create_node) {
	ASSERT_NO_THROW(Node<int> n(1, nullptr));
}

TEST(node, can_return_value) {
	Node<int> n(1, nullptr);
	Node<int> n1(2, &n);
	ASSERT_NO_THROW(n1.value);
}

TEST(node, returns_value_correctly) {
	Node<int> n(1, nullptr);
	Node<int> n1(2, &n);
	ASSERT_EQ(n1.value, 2);
}


//	List tests

TEST(list, can_create_list_of_positive_size) {
	ASSERT_NO_THROW(List<int> l(4));
}

TEST(list, can_create_empty_list) {
	ASSERT_NO_THROW(List<int> l());
}

TEST(list, cant_create_list_of_negative_size) {
	ASSERT_ANY_THROW(List<int> l(-3));
}

TEST(list, can_create_copied_list) {
	List<int> l(3);
	ASSERT_NO_THROW(List<int> l1(l));
}

TEST(list, copied_list_is_equal_to_source) {
	bool res = true;
	List<int> l(3);
	List<int> l1(l);
	for (int i = 0; i < 3; i++) {
		if (l[i].value != l1[i].value) {
			res = false;
		}
	}
	ASSERT_EQ(res, true);
}

TEST(list, copied_list_has_its_own_memory) {
	List<int> l(3);
	List<int> l1(l);
	ASSERT_NE(&l, &l1);
}

TEST(list, can_print_list) {
	List<int> l(3);
	ASSERT_NO_THROW(l.print());
}

TEST(list, can_get_size) {
	List<int> l(3);
	ASSERT_EQ(l.size(), 3);
}

TEST(list, can_move_list) {
	ASSERT_NO_THROW(List<int> l(List<int>(3)));
}

TEST(list, moved_list_has_no_memory_pointer) {
	List<int> l(3);
	List<int> l1 = std::move(l);
	ASSERT_EQ(l.GetHead(), nullptr);
}

TEST(list, list_memory_pointer_moved_to_new_one) {
	List<int> l(3);
	auto head = l.GetHead();
	List<int> l1 = std::move(l);
	ASSERT_EQ(l1.GetHead(), head);
}

TEST(list, moved_list_equal_to_source) {
	List<int> l(3);
	List<int> l_copy(l);
	List<int> l1 = std::move(l);
	
	bool res = true;
	for (int i = 0; i < 3; i++) {
		if (l_copy[i].value != l1[i].value) {
			res = false;
		}
	}
	ASSERT_EQ(res, true);
}

TEST(list, can_insert_node) {
	List<int> l(7);
	l.insert_after(1, &l[2]);
	ASSERT_EQ(l[3].value, 1);
}

TEST(list, can_insert_node_using_iterator) {
	List<int> l(7);
	l.insert_after(1, &(*l.begin()));
	ASSERT_EQ(l[1].value, 1);
}

TEST(list, cant_insert_after_end_iterator) {
	List<int> l(7);
	ASSERT_ANY_THROW(l.insert_after(1, &(*l.end())));
}

TEST(list, insert_changes_list_size) {
	List<int> l(7);
	l.insert_after(1, &(*l.begin()));
	ASSERT_EQ(l.size(), 8);
}

TEST(list, can_insert_in_front) {
	List<int> l(7);
	l.insert_front(1);
	ASSERT_EQ((*l.begin()).value, 1);
}

TEST(list, insert_in_front_changes_list_size) {
	List<int> l(7);
	l.insert_front(1);
	ASSERT_EQ(l.size(), 8);
}

TEST(list, can_erase_node) {
	List<int> l(7);
	auto erased_ptr = &l[3];
	l.erase_after(&l[2]);
	ASSERT_NE(&l[3], erased_ptr);
}

TEST(list, erase_changes_list_size) {
	List<int> l(7);
	l.erase_after(&l[2]);
	ASSERT_EQ(l.size(), 6);
}

TEST(list, erasing_after_last_element_doesnt_change_list) {
	List<int> l(7);
	l.erase_after(&l[6]);
	ASSERT_EQ(l.size(), 7);
}

TEST(list, can_erase_front) {
	List<int> l(7);
	auto erased_front = &(*l.begin());
	l.erase_front();
	ASSERT_NE(&(*l.begin()), erased_front);
}

TEST(list, erase_front_changes_list_size) {
	List<int> l(7);
	l.erase_front();
	ASSERT_EQ(l.size(), 6);
}