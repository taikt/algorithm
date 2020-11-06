/**
 * Filename: StackParam2.h
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file provides the header file for a second 
 *              Stack template class for a parameterized stack type.  
 *              This file does not use exception handling.
 */

#ifndef STACKPARAM2_H
#define STACKPARAM2_H

template <typename T, int SIZE> 
class Stack {

 public:

  Stack(void);

  void push(const T &item);
  void pop(T &item);
  bool isEmpty(void) const;
  bool isFull(void) const;

 private:
  int top_, size_;
  T stack_[SIZE];
};

#include "StackParam2.cpp"

#endif
