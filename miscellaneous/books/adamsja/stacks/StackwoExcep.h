/**
 * Filename: StackwoException.h
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file implements an abstract data type stack class using 
 *              data hiding. This file does use exception handling.
 */

#ifndef STACKWOEXCEPT_H
#define STACKWOEXCEPT_H

#include <stdlib.h>

// Type of Stack element
typedef int T;

class Stack {

 public:

  /* Constructors */
  Stack (size_t size);

  /* Destructor */
  ~Stack(void);

  void push(const T &item);
  void pop (T &item);

  int top(T &cur_top);

  bool isEmpty(void) const;
  bool isFull(void) const;

 private:
  size_t top_, size_;
  T *stack_;
};

#endif

