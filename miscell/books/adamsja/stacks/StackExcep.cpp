/**
 * Filename: StackExcep.cpp
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file implements an abstract data type stack class using 
 *              data hiding. This file does use exception handling.
 */

#include "StackExcep.h"

Stack::Stack (size_t size): top_(0), size_(size), stack_(new T[size]) {}

Stack::~Stack(void)
{
  delete [] stack_;
}

void Stack::push (const T &item) throw(Stack::Overflow)
{
  if (isFull())
    throw Stack::Overflow();
  stack_[top_] = item;
  top_++;
}

void Stack::pop (T &item) throw(Stack::Underflow)
{
  if (isEmpty())
      throw Stack::Underflow();
  item = stack_[--top_];
}

int Stack::top (T &item) throw(Stack::Overflow, Stack::Underflow)
{
  if (isFull())
    throw Stack::Overflow();
  else if (isEmpty())
     throw Stack::Underflow();
  item = stack_[top_ - 1];

  return item;
}
bool Stack::isEmpty (void) const
{
  return top_ == 0;
}

bool Stack::isFull (void) const
{
  return top_ == size_;
}

