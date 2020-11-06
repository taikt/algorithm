/** A test file for Stack using the Stack Template Class wit Virtual Functions
    Julie A. Adams
**/
#include <iostream>

#include "V_Stack.h"
#include "L_Stack.h"


/* by writing "using std::..." we can then access the commands with 
   typing "std::..." everytime.  We can simply use the command, such as cout. */

using namespace std; // required to use cin, cout, and endl

template <typename T> 
Stack<T> *make_stack (bool useV_Stack) {
  if (useV_Stack)
    return new V_Stack<T>(10);
  else
    return new L_Stack<T>(10);

  // http://msdn.microsoft.com/en-us/library/e4213hs1%28VS.71%29.aspx
  //  return useV_Stack ? new V_Stack<T>(10) : new L_Stack<T>(10); 
}

template <typename T> 
void testStack (Stack<T> *stack, const T &item){
  T popItem;
  stack->push(item);
  stack->pop(popItem);
  cout << "Item popped in testStack: " << popItem << endl;
  } 

int main (void) 
{
  /* create a Vector Stack */
  V_Stack<int> stack1(10);
  stack1.push(10);
  stack1.push(40);
  int iItem;
  stack1.pop(iItem);
  cout << "item popped from stack1: " << iItem << endl;
  
  /* create a linked list stack */
  L_Stack<double> stack2(5);
  stack2.push(5.5); // 1
  stack2.push(5.6); // 2
  double dItem;
  stack2.pop(dItem);
  cout << "item popped from stack2: " << dItem << endl;
 
  stack1.push(-291);

  stack2.push(3.45); //2

  stack1.push(34);
  stack1.push(6);
  stack1.pop(iItem);
  cout << "item popped from Stack 1: " << iItem << endl;
  
  stack2.push(-6.99); //3
  stack2.push(-10.99); //4
  stack2.push(7.89); //5
  stack2.push(0.23);
  stack2.pop(dItem);
  cout << "item popped from double stack 2: " << dItem << endl; 
  
  //stack2.top_ - 3.1416; // Access violation
 
  testStack<double>(make_stack<double>(true), 15);
  
  //Termination and descruction is handled automatically.
  
  return 0;
}
  
