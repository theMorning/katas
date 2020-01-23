#include <sstream>
#include <gtest/gtest.h>
#include "linked_list.cpp"

LinkedList<int> initialize_list_single() {
  LinkedList<int> linkedList {};
  linkedList.push_front(42);

  return linkedList;
}

LinkedList<int> initialize_list(int size) {
  LinkedList<int> linkedList {};
  for(auto i = 0; i < size; i++) {
    linkedList.push_front(i * i);
  }

  return linkedList;
}

TEST(LinkedListTest, CreatedListHasZeroLength) {
  LinkedList<int> linkedList {};
  ASSERT_EQ(linkedList.length, 0);
}

TEST(LinkedListTest, CreatedListHasNullFront) {
  LinkedList<int> linkedList {};
  Node<int> *front = linkedList.get_front();
  ASSERT_EQ(front, nullptr);
}

TEST(LinkedListTest, PushFrontIncrementLengthSingle) {
  LinkedList<int> linkedList = initialize_list_single();
  ASSERT_EQ(linkedList.length, 1);
}

TEST(LinkedListTest, GetFrontValueSingle) {
  LinkedList<int> linkedList = initialize_list_single();
  Node<int> *front = linkedList.get_front();
  ASSERT_EQ(front->data, 42);
}

TEST(LinkedListTest, GetFrontNextSingle) {
  LinkedList<int> linkedList = initialize_list_single();
  Node<int> *front = linkedList.get_front();
  ASSERT_EQ(front->next, nullptr);
}

TEST(LinkedListTest, GetNextPointerTwoNodes) {
  LinkedList<int> linkedList {};
  linkedList.push_front(4);
  Node<int> *first_inserted = linkedList.get_front();
  linkedList.push_front(16);
  Node<int> *head = linkedList.get_front();
  ASSERT_EQ(head->next, first_inserted);
  ASSERT_EQ(first_inserted->next, nullptr);
}

TEST(LinkedListTest, PushFrontIncrementLength) {
  LinkedList<int> linkedList = initialize_list(4);
  ASSERT_EQ(linkedList.length, 4);
}

TEST(LinkedListTest, GetFrontValue) {
  LinkedList<int> linkedList = initialize_list(4);
  Node<int> *front = linkedList.get_front();
  ASSERT_EQ(front->data, 9);
}

TEST(LinkedListTest, PopFrontLength) {
  LinkedList<int> linkedList = initialize_list(4);
  Node<int> *front = linkedList.pop_front();
  ASSERT_EQ(linkedList.length, 3);
  delete front;
}

TEST(LinkedListTest, PopFrontData) {
  LinkedList<int> linkedList = initialize_list(4);
  Node<int> *get_node = linkedList.get_front();
  Node<int> *popped_node = linkedList.pop_front();
  ASSERT_EQ(get_node->data, popped_node->data);
  ASSERT_EQ(get_node->next, popped_node->next);
  delete popped_node;
}

TEST(LinkedListTest, PopFrontUpdateHead) {
  LinkedList<int> linkedList = initialize_list(2);
  Node<int> *saved_head = linkedList.get_front();
  linkedList.push_front(99);
  Node<int> *popped_node = linkedList.pop_front();
  Node<int> *head = linkedList.get_front();
  ASSERT_EQ(saved_head, head);
  delete popped_node;
}

TEST(LinkedListTest, PrintEmpty) {
  LinkedList<int> linkedList {};
  std::ostringstream output_buffer;
  linkedList.print(output_buffer);
  ASSERT_EQ(output_buffer.str(), "");
}

TEST(LinkedListTest, PrintSingle) {
  LinkedList<int> linkedList {};
  linkedList.push_front(9);
  std::ostringstream output_buffer;
  linkedList.print(output_buffer);
  ASSERT_EQ(output_buffer.str(), "9\n");
}

TEST(LinkedListTest, Print) {
  LinkedList<int> linkedList = initialize_list(4);
  std::ostringstream output_buffer;
  linkedList.print(output_buffer);
  ASSERT_EQ(output_buffer.str(), "9\n4\n1\n0\n");
}