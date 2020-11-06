/* File: mapExample.cpp
 * Authors: Deitel & Deitel
 * Contributors: J. Adams
 * Description: Testing Standard Library class map
 */
#include <iostream>
#include <map>
#include <iterator>

int main()
{
   // Create a type def of a map that has int keys in ascending order and 
  //  stores double values.
   typedef std::map< int, double, std::less< int > > MID;

   // Define an instance of the map
   MID pairs;

   // Insert elements into the map
   pairs.insert(MID::value_type(15, 2.7));
   pairs.insert(MID::value_type(30, 111.11));
   pairs.insert(MID::value_type(5, 1010.1));
   pairs.insert(MID::value_type(10, 22.22));
   pairs.insert(MID::value_type(25, 33.333));
   pairs.insert(MID::value_type(5, 77.54)); // dupe ignored
   pairs.insert(MID::value_type(20, 9.345));
   pairs.insert(MID::value_type(15, 99.3)); // dupe ignored
   std::cout << "pairs contains:\nKey\tValue\n";

   // Define a constant iterator to be used for outputing 
   // the information in the map.   
   MID::const_iterator iter;

   for (iter = pairs.begin(); iter != pairs.end(); ++iter)
     std::cout << iter->first << '\t' << iter->second << std::endl;

   pairs[25] = 9999.99;  // change existing value for 25
   pairs[11] = 8765.43;  // insert new value for 40
   std::cout << std::endl << "After subscript operations, pairs contains:"
	     << "\nKey\tValue" << std::endl;
   
   for (iter = pairs.begin(); iter != pairs.end(); ++iter)
     std::cout << iter->first << '\t' << iter->second << std::endl;

   std::cout << std::endl;
   return 0;
}

/*
pairs contains:
Key     Value
5       1010.1
10      22.22
15      2.7
20      9.345
25      33.333
30      111.11

After subscript operations, pairs contains:
Key     Value
5       1010.1
10      22.22
15      2.7
20      9.345
25      9999.99
30      111.11
40      8765.43
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
