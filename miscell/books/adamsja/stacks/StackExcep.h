/**
 * Filename: StackExcep.h
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file implements an abstract data type stack class using 
 *              data hiding. This file does use exception handling.
 */

#ifndef STACKEXCEP_H
#define STACKEXCEP_H

#include <stdlib.h>

// Type of Stack element
typedef int T;

class Stack {

 public:
  class Underflow { 
    public:
       Underflow() : message("Exception: stack underflow") {}
       const char *what() const { return message; }
    private:
    const char *message; 
  };

  class Overflow { 
    public:
       Overflow() : message("Exception: stack overflow") {}
       const char *what() const { return message; }
    private:
    const char *message; 
   };

  /* Constructors */
  Stack (size_t size);

  /* Destructor */
  ~Stack(void);

  void push(const T &item) throw(Overflow);
  void pop (T &item) throw(Underflow);

  int top(T &cur_top) throw(Overflow, Underflow);

  bool isEmpty(void) const;
  bool isFull(void) const;

 private:
  size_t top_, size_;
  T *stack_;
};

#endif

