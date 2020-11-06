/**
 * Filename: StackBig3.cpp
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file impliments an abstract data type stack class using 
 *              data hiding. This file does not use exception handling.
 */
#include "StackBig3.h"

Stack::Stack(size_t size) : top_(0), size_(size), stack_(new T[size]) {}

Stack::Stack(const Stack &inStack) : top_(inStack.top_), size_(inStack.size_), 
                                     stack_(new T[inStack.size_]) {
  for (int i = 0; i < inStack.size_; i++) {
    stack_[i] = inStack.stack_[i];
  }
}

Stack::~Stack(void) {
  delete [] stack_;
}

void Stack::operator=(const Stack &inStack)
{
  if (this != &inStack)
    {
      T *temp_stack = new T[inStack.size_];
      delete [] stack_;
      for (int i = 0; i < inStack.size_; i++)
	{
	  temp_stack[i] = inStack.stack_[i];
	}
      stack_ = temp_stack;
      top_ = inStack.top_;
      size_ = inStack.size_;
    }
}

void Stack::push(const T &item)
{
  stack_[top_] = item;
  top_++;
}

void Stack::pop(T &item)
{
  item = stack_[--top_];
}

int Stack::top(T &item)
{
  item = stack_[top_ - 1];

  return item;
}
bool Stack::isEmpty(void) const
{
  return top_ == 0;
}

bool Stack::isFull(void) const
{
  return top_ == size_;
}

