/**
 * Filename: StackBig3Main.cpp
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file is a test file for the abstract data type stack class
 *              implementation using data hiding. This file does not use 
 *              exception handling.
 */

/** A test file for Stack without Exceptions
    Julie A. Adams
**/
#include <iostream>

#include "StackBig3.h"

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
  Stack stack3(3);

  if (!stack1.isEmpty())
    stack3 = stack1;

  if (!stack3.isEmpty()) 
  {
    stack3.top(top_item);
    std::cout << "the top item on stack3 is: " << top_item << std::endl;
    
  Stack stack4(stack1);  }


  if (!stack4.isEmpty()) 
  {
    stack4.top(top_item);
    std::cout << "the top item on stack4 is: " << top_item << std::endl;
  }
  //Termination and descruction is handled automatically.
  
  return 0;
}
  
