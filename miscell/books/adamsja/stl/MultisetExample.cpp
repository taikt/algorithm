/* multisetExample.cpp
 * Authors: Deitel & Deitel
 * Contributors: J. Adams
 * Description: Testing Standard Library class multiset
 */
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
   const int SIZE = 10;
   int arr[ SIZE ] = { 7, 22, 9, 1, 18, 30, 100, 22, 85, 13 };

   // define the type IMS for a multiset that stores int and sorts in ascending
   // order.
   typedef std::multiset< int, std::less< int > > IMS;

   // Define an instance of an integer multiset
   IMS intMultiset;  

   // Create an output stream iterator that will put an additional space 
   // between each int.
   std::ostream_iterator< int > output( std::cout, " " );

   // Output the number of elements in the set that are 15.
   std::cout << "There are currently " << intMultiset.count( 15 )
        << " values of 15 in the multiset\n\n";   

   // Insert two elements 15.
   intMultiset.insert( 15 );
   intMultiset.insert( 15 );

   // Output the count again.
   std::cout << "After inserts, there are " 
        << intMultiset.count( 15 )
        << " values of 15 in the multiset\n\n";

   // Create a constant interator
   IMS::const_iterator result;

   // Get an iterator for the element 15.
   result = intMultiset.find( 15 );  

   if ( result != intMultiset.end() ) // if iterator not at end
     std::cout << "Found value 15\n\n";     // found search value 15
   
   result = intMultiset.find( 20 );

   if ( result == intMultiset.end() )    // will be true hence
     std::cout << "Did not find value 20\n\n"; // did not find 20

   intMultiset.insert( arr, arr + SIZE ); // add array a to multiset
   std::cout << "After insert intMultiset contains:\n";

   // Output the multiset from beginning to end.
   std::copy( intMultiset.begin(), intMultiset.end(), output );

   std::cout << "\n\nLower bound of 22: " 
        << *( intMultiset.lower_bound( 22 ) );
   std::cout << "\nUpper bound of 22: " 
	     << *( intMultiset.upper_bound( 22 ) ) << std::endl << std::endl;

   int arr2[ SIZE ] = { 15, 22, 8, 1, 65, 70, 99, 22, 25, 17 };
   
   // Insert arr2 into a multiset
   IMS intMultiset2;
   intMultiset2.insert(arr2, arr2 + SIZE);

   // Create the union of two multisets
   std::cout << "Union: ";
   std::set_union(intMultiset.begin(), intMultiset.end(),
	     intMultiset2.begin(), intMultiset2.end(),
		  std::ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl << std::endl;
   
   // Find the intersection of two multisets
   std::cout << "Intersection: ";
   std::set_intersection(intMultiset.begin(), intMultiset.end(),
		    intMultiset2.begin(), intMultiset2.end(),
			 std::ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl << std::endl;
   
   // Determine the difference between two multisets and store the result
   // into a third multiset
   IMS intMultiset3;
   std::set_difference(intMultiset.begin(), intMultiset.end(),
		  intMultiset2.begin(), intMultiset2.end(),
		  inserter(intMultiset3, intMultiset3.end()));
   std::cout << "Set intMultiset3 to the difference between intMultiset and" 
	     << std::endl << "intMultiset2: ";
   std::copy(intMultiset3.begin(), intMultiset3.end(),
	     std::ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;

   return 0;
}

/************** The program output *******************
There are currently 0 values of 15 in the multiset

After inserts, there are 2 values of 15 in the multiset

Found value 15

Did not find value 20

After insert intMultiset contains:
1 7 9 13 15 15 18 22 22 30 85 100 

Lower bound of 22: 22
Upper bound of 22: 30

Union: 11 7 8 9 13 15 15 17 18 22 22 25 30 65 70 85 99 100

Intersection 1 15 22 22

Set intMultiset3 t0 the difference between intMultiset and
intMultiset2: 7 9 13 15 18 30 85 100 
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
