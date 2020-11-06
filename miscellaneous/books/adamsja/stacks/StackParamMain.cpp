/**
 * Filename: StackParamMain.cpp
 * Class: CS251
 *
 * @author Julie A. Adams
 * Description: This file provides the a main function for testing 
 *              the Stack template class for a parameterized stack type.  
 *              This file does not use exception handling.
 */

#include <iostream>

#include "StackParam.h"

/* by writing "using std::..." we can then access the commands with 
   typing "std::..." everytime.  We can simply use the command, such as cout. */

using namespace std; // required to use cin, cout, and endl


int main (void) 
{
  /* create multiple stacks */
  Stack<int> stack1(1000);
  Stack<double> stack2(10);
 

  int int_item;
  double dbl_item;
  
 stack1.push(-291);
 stack1.push(10);
 stack1.push(43);
 stack1.pop(int_item);
 cout << "The item popped off of Stack 1 is: " << int_item << endl;

 stack2.push(1);
 stack2.push(-3.45);
 stack2.push(6.88);
 stack2.pop(dbl_item);
 cout << "The item popped off of Stack 2 is: " << dbl_item << endl;
 //stack2.top_ - 3.1416; // Access violation

  //Termination and destruction is handled automatically.
  
  return 0;
}
  
