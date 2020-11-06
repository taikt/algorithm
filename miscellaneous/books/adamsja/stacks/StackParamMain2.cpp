/**
 * Filename: StackParamMain.cpp
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file provides the test file for the second 
 *              Stack template class for a parameterized stack type.  
 *              This file does not use exception handling.
 */

#include <iostream>

#include "StackParam2.h"

/* by writing "using std::..." we can then access the commands with 
   typing "std::..." everytime.  We can simply use the command, such as cout. */

using namespace std; // required to use cin, cout, and endl


int main (void) 
{
  /* create multiple stacks */
  Stack<int, 1000> stack1;
  Stack<double, 10> stack2;
  int item;
 
  stack1.push(-291);

  stack2.push(3.45);

  stack1.push(34);
  stack1.push(6);
  stack1.pop(item);
  cout << "item popped from Stack 1: " << item << endl;
  
  stack2.push(-6.99);
  //stack2.pop(item);
  
  double item2;
  stack2.pop(item2);
  cout << "item popped from double stack 2: " << item2 << endl; 

  //stack2.top_ - 3.1416; // Access violation
 
  //Termination and destruction is handled automatically.
  
  return 0;
}
  
