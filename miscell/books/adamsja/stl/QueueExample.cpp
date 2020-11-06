/* File: queueExample.cpp
 * Author: Deitel & Deitel
 * Contributors: J. Adams
 * Description: Testing Standard Library adapter class 
 * template queue
*/
#include <iostream>
#include <queue>

int main()
{
   // create a queue of double values
  // Default is a Deque, can also use a list
  std::queue< double > values;
   
   // Store values into the queue
   values.push( 9.8 );
   values.push( 5.4 );
   values.push( 3.2 );
  
   std::cout << "Popping from values: ";
   
   while ( !values.empty() ) {
     std::cout << values.front() << ' ';  // does not remove
      values.pop();                   // removes element
   }

   std::cout << std::endl;
   return 0;
}

/*

Popping from values: 3.2 9.8 5.4

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
