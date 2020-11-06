/**
 * Filename: StackBig3.h
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file impliments an abstract data type stack class using 
 *              data hiding. This file does not use exception handling.
 */

#ifndef STACKBIG3_H
#define STACKBIG3_H

// This header defines "size_t"
#include <stdlib.h>

// Type of Stack element
typedef int T;


class Stack {

 public:
  /* Constrctors */
  Stack(size_t size);
  Stack(const Stack &inStack);

  void operator=(const Stack &);

  /* Destructor */
  ~Stack(void);

  void push(const T &item);
  void pop(T &item);

  int top(T &cur_top);

  bool isEmpty(void) const;
  bool isFull(void) const;

 private:
  size_t top_, size_;
  T *stack_;
};

#endif

