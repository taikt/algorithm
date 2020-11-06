/**
 * Filename: StackParam2.cpp
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file provides the implementation of a second 
 *              Stack template class for a parameterized stack type.  
 *              This file does not use exception handling.
 */
#ifndef STACKPARAM2_CPP
#define STACKPARAM2_CPP

#include <iostream>
#include "StackParam2.h"

using namespace std;

template <typename T, int SIZE> inline
Stack<T, SIZE>::Stack (void): top_(0),  size_(SIZE) {}

template <typename T, int SIZE> inline
void Stack<T, SIZE>::push (const T &item) 
{
  stack_[top_] = item;
  top_++;
}

template <typename T, int SIZE> inline
void Stack<T, SIZE>::pop (T &item) 
{
 item = stack_[--top_];
}

template <typename T, int SIZE> inline
bool Stack<T, SIZE>::isEmpty (void) const
{
  return top_ == 0;
}

template <typename T, int SIZE> inline
bool Stack<T, SIZE>::isFull (void) const
{
  return top_ == size_;
}

#endif
