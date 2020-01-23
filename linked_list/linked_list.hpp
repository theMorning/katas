#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include <iostream>

template <class T> struct Node {
  T data;
  Node<T> *next;
};

template <class T> class LinkedList {
private:
  Node<T> *head;

public:
  LinkedList() : head(nullptr) {}
  void push_front(const T item);
  Node<T> *get_front();

  Node<T> *pop_front();
  void print(std::ostream& cout = std::cout);
  int length = 0;
};

#endif
