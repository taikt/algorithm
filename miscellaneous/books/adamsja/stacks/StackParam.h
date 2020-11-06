/**
 * Filename: StackParam.h
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file provides a Stack template class for a 
 *              parameterized stack type.  This file does not  
 *              use exception handling.
 */

#ifndef STACKPARAM_H
#define STACKPARAM_H

template <typename T> 
class Stack {

 public:
  Stack(int size);

  ~Stack(void);

  void push(const T &item);
  void pop(T &item);
  bool is_empty(void) const;
  bool is_full(void) const;

 private:
  int top_, size_;
  T *stack_;
};

#include "StackParam.cpp"

#endif
