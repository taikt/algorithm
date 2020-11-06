/** Stack Example: Vector Stack Template Implementation using the Stack 
Template with virtual Functions
    Julie A. Adams
**/
#ifndef V_STACK_CPP
#define V_STACK_CPP

#include "V_Stack.h"

template <typename T>
V_Stack<T>::V_Stack (int size): top_(size), stack_(size) {}

template <typename T>
V_Stack<T>::~V_Stack() {
  top_ = 0;
}

template <typename T>
void V_Stack<T>::push (const T &item) 
{
  if (!isFull()) {
    stack_.push_back(item);
  }
}

template <typename T>
void V_Stack<T>::pop (T &item) 
{
  if (!isEmpty()) {
    item = stack_.back();
    stack_.pop_back();
  }
}

template <typename T>
bool V_Stack<T>::isEmpty (void) const
{
  return top_ == 0;
}

template <typename T>
bool V_Stack<T>::isFull (void) const
{
  return top_ > stack_.size();
}

#endif
