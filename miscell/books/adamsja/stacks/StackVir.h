/** Stack Example: Stack Template Implementation using Virtual Funcitons Stack
    Julie A. Adams
**/

#ifndef STACKVIR_H
#define STACKVIR_H

template <typename T> 
class Stack {

 public:

  // No contstructor in this class

  virtual ~Stack(void) {} // requires an implementation

  virtual void push(const T &item) = 0;
  virtual void pop(T &item) = 0;
  virtual bool isEmpty(void) const = 0;
  virtual bool isFull(void) const = 0;
  void top(T &item) { //Template method
    pop(item);
    push(item);
  }

};

#endif
