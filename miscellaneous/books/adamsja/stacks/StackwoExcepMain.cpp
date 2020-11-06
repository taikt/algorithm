/**
 * Filename: StackwoExceptionMain.cpp
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file is a tester file for the Stack class.
 */

#include <iostream>

#include "StackwoExcep.h"

/* by writing "using std::..." we can then access the commands with 
   typing "std::..." everytime.  We can simply use the command, such as cout. */

int main (void) 
{
  /* create multiple stacks */
  Stack stack1(1), stack2(100);
  
  T item, top_item;
  
  if (!stack1.isFull())
    stack1.push(473);

  if (!stack1.isEmpty())
  {
    stack1.top(top_item);
    std::cout << "the top item on stack1 is: " << top_item << std::endl;
  }

  if (!stack2.isFull())
    stack2.push(2112);

  if (!stack2.isEmpty())
  {
    stack2.pop(item);
    std::cout << "the item popped off the stack is: " << item << std::endl;
  }
  //access violation caught at compile-time
  //stack2.top_ = 10;


  //Termination and destruction is handled automatically.
  
  return 0;
}
  
