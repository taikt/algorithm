/** Stack Example: Linked List Stack Template Implementation using the Stack 
Template with virtual Functions
    Julie A. Adams
**/
#ifndef L_STACK_CPP
#define L_STACK_CPP

#include "node.h"
#include "L_Stack.h"

template <typename T>
L_Stack<T>::L_Stack (size_t size): numItems_(0), size_(size), head_(0) {}

template <typename T>
L_Stack<T>::~L_Stack(){
  if (!isEmpty()){
    Node<T> *currentPtr(head_), *nextPtr(0);
    while (currentPtr != 0 ){
      nextPtr = currentPtr->getNext();
      delete currentPtr;
      currentPtr = nextPtr;
    }
  }
}

template <typename T>
void L_Stack<T>::push(const T &item){
  if (!isFull()) {
    Node<T>* newNode = new Node<T>(item, 0);
    head_ = newNode;
    numItems_++;
  }
}

template <typename T>
void L_Stack<T>::pop(T &top_item) 
{
  if (!isEmpty()) {
    top_item = head_->getItem();
    Node<T> *t(head_);
    head_ = t->getNext();
    delete t;
    numItems_--;
  }
}

#endif
