/**
 * Filename: StackwoException.cpp
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file implements an abstract data type stack class using 
 *              data hiding.
 */

#include "StackwoExcep.h"

Stack::Stack (size_t size): top_(0), size_(size), stack_(new T[size]) {}

Stack::~Stack(void)
{
  delete [] stack_;
}

void Stack::push (const T &item) 
{
  stack_[top_] = item;
  top_++;
}

void Stack::pop (T &item) 
{
  item = stack_[--top_];
}

int Stack::top (T &item) 
{
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

