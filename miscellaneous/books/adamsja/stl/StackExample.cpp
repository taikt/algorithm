/* File: stackExample.cpp
 * Authors: Deitel & Deitel
 * Contributors: J. Adams
 * Description: Testing Standard Library class stack
 */
#include <iostream>
#include <stack>
#include <vector>
#include <list>

/* name: popElements
 * 
 * Description: The function pops an element off the top
 *                      of the stack.
 *
 * Arguments: A stack (independent of the underlying
 *                     STL data structure.
 * 
 * Modifies: Nothing
 * Returns: void
 * Preconditions: The stack exists
 * Postconditions: The stack is empty.
 * Exceptions: none:
 */
template< class T >
void popElements( T &s );

int main()
{
   // Define a stack that uses a Deque as the data structure
  std::stack< int > intDequeStack;   

   // Define a stack that uses a vector as the data structure
  std::stack< int, std::vector< int > > intVectorStack;

   // Define a stack that uses a list as the data structure.
  std::stack< int, std::list< int > > intListStack;

   // Put data in all three stacks.
   for ( int i = 0; i < 10; ++i ) {
      intDequeStack.push( i );
      intVectorStack.push( i );
      intListStack.push( i );
   }

   std::cout << "Popping from intDequeStack: ";
   popElements( intDequeStack );
   std::cout << std::endl << "Popping from intVectorStack: ";
   popElements( intVectorStack );
   std::cout << std::endl << "Popping from intListStack: ";
   popElements( intListStack );

   std::cout << std::endl;
   return 0;
}

template< class T >
void popElements( T &stackData )
{
   while ( !stackData.empty() ) {
     std::cout << stackData.top() << ' ';
      stackData.pop();
   }
}

/*
Popping from intDequeStack: 9 8 7 6 5 4 3 2 1 0 
Popping from intVectorStack: 9 8 7 6 5 4 3 2 1 0 
Popping from intListStack: 9 8 7 6 5 4 3 2 1 0 
*/
/**************************************************************************
 * (C) Copyright 2000 by Deitel & Associates, Inc. and Prentice Hall.     *
 * All Rights Reserved.                                                   *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
