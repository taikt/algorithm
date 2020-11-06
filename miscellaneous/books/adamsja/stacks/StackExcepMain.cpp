/**
 * Filename: StackExcepMain.cpp
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file is a tester file for the Stack class with exceptions.
 *              This file uses exception handling.
 */

#include <iostream>

#include "StackExcep.h"

/* by writing "using std::..." we can then access the commands with 
   typing "std::..." everytime.  We can simply use the command, such as cout. */

int main (void) 
{
  /* create multiple stacks */
  Stack stack1(1), stack2(100);
  
  try{
    T item, top_item;
  
    stack1.push(473);
    stack1.push(10); //Exception, pushed onto full stack!

    stack2.pop(item); // Exception, popped empty stack!
    //stack2.top_ = 10; //Access violation caught!
  } 
  catch(Stack::Underflow excep) {  
    std::cout << excep.what() << std::endl;
    //cout << "Exception: Underflow" << endl;
  }
  catch (Stack::Overflow excep ) { 
    std::cout << excep.what() << std::endl;
    //cout << "Exception: Overflow" << endl; 
  }
  catch (...) { 
    std::cout << "Exception: Unknown" << std::endl;
  }

  //Termination and destruction is handled automatically.
  
  return 0;
}
  
