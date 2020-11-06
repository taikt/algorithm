/* File: setExample.cpp
 * Authors: Deitel & Deitel
 * Contributors: J. Adams
 * Description: Testing Standard Library class set
 */
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
   // define a set data type that stored Doubles in ascending order.
  typedef std::set< double, std::less< double > > DOUBLE_SET;

   const int SIZE = 5;
   double arr[ SIZE ] = { 2.1, 4.2, 9.5, 2.1, 3.7 }; 

   // define a set variable of type DOUBLE_SET  
   // Initalize doubleSet to the values stored in arr.
   DOUBLE_SET doubleSet( arr, arr + SIZE );

  // Create an output stream iterator
   std::ostream_iterator< double > output( std::cout, " " );

   std::cout << "doubleSet contains: ";

   // Output the current values of the set.
   std::copy( doubleSet.begin(), doubleSet.end(), output );

   // Define a pair to extract store elements into.
   std::pair< DOUBLE_SET::const_iterator, bool > pairValue;

   // Insert a value that is not in the set
   pairValue = doubleSet.insert( 13.8 ); // value not in set

   std::cout << std::endl << *( pairValue.first ) 
        << ( pairValue.second ? " was" : " was not" ) << " inserted";
   std::cout << "\ndoubleSet contains: ";
   std::copy( doubleSet.begin(), doubleSet.end(), output );

   // insert a value that is alread in the set.
   pairValue = doubleSet.insert( 9.5 );  
   std::cout << std::endl << *( pairValue.first ) 
        << ( pairValue.second ? " was" : " was not" ) << " inserted";
   std::cout << "\ndoubleSet contains: ";
   std::copy( doubleSet.begin(), doubleSet.end(), output );

   std::cout << std::endl;
   return 0;
}

/******** Output *****************
doubleSet contains: 2.1 3.7 4.2 9.5 
13.8 was inserted
doubleSet contains: 2.1 3.7 4.2 9.5 13.8 
9.5 was not inserted
doubleSet contains: 2.1 3.7 4.2 9.5 13.8 
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
