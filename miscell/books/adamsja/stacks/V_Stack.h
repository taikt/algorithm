/** Stack Example: Vector Stack Template Implementation using the Stack Template with virtual Functions
    Julie A. Adams
**/

#ifndef VSTACK_H
#define VSTACK_H

#include <vector>
#include "StackVir.h"

template <typename T> 
class V_Stack : public Stack<T>{

 public:

  enum {DEFAULT_SIZE = 100};

  V_Stack(int size = DEFAULT_SIZE);
  
  virtual ~V_Stack (void);
  
  virtual void push(const T &item);
  virtual void pop(T &item);
  virtual bool isEmpty(void) const;
  virtual bool isFull(void) const;

  // Note: No top function required
  
 private:
  int top_; 
  std::vector<T> stack_; 

};

#include "V_Stack.cpp"

#endif
