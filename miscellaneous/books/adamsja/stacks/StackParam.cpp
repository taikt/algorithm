/**
 * Filename: StackParam.cpp
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file provides the implementation for a Stack template 
 *              class for a parameterized stack type.  This file does not  
 *              use exception handling.
 */
#ifndef STACKPARAM_CPP
#define STACKPARAM_CPP

#include "StackParam.h"

template <typename T> 
Stack<T>::Stack (int size): top_(0), size_(size), stack_(new T[size]) {}

template <typename T> inline
Stack<T>::~Stack(void)
{
  delete [] stack_;
}

template <typename T> inline
void Stack<T>::push (const T &item) 
{
  stack_[top_] = item;
  top_++;
}

template <typename T> inline
void Stack<T>::pop (T &item) 
{
 item = stack_[--top_];
}

template <typename T> inline
bool Stack<T>::is_empty (void) const
{
  return top_ == 0;
}

template <typename T> inline
bool Stack<T>::is_full (void) const
{
  return top_ == size_;
}

#endif
