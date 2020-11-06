/** Stack Example: Linked List Stack Template Implementation using the Stack Template with virtual Functions
    Julie A. Adams
**/

#ifndef LSTACK_H
#define LSTACK_H

#include <stdlib.h>

#include "StackVir.h"

template <typename T> class Node;

template <typename T> 
class L_Stack : public Stack<T>{

 public:

  enum {DEFAULT_SIZE = 100};
  
  L_Stack(size_t size = DEFAULT_SIZE);
  
  virtual ~L_Stack(void);
  
  virtual void push(const T &new_item);
  virtual void pop(T &top_item);
  virtual bool isEmpty(void) const {return (head_ == 0); }
  virtual bool isFull(void) const {return numItems_ >= size_; }

  // Note: No top function required
  
 private:
  size_t numItems_;
  size_t size_;
  /*Head of linked list of Node<T>'s */
  Node<T> *head_; 

};

#include "L_Stack.cpp"

#endif
