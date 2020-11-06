/* File: multimapExample.cpp
 * Authors: Deitel & Deitel
 * Contributors: J. Adams
 * Description: Testing Standard Library class multimap
 */
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main()
{
  // Define the particular multimap data type. The key is an int and keys are
  // sorted in ascending order. Doubles are stored in the multimap.
  typedef std::multimap< int, double, std::less<int> > MMID;

  // Define an instance of the Multimap
  MMID pairs;

  // Count how many pairs have the key 15
  std::cout << "There are currently " << pairs.count(15)
	    << " pairs with key 15 in the multimap" << std::endl << std::endl;

  // Insert items into the map

  pairs.insert( MMID::value_type(15, 99.3));
  pairs.insert( MMID::value_type(15, 2.7));
  // Count how many pairs have the key 15
  std::cout << "After inserts, there are " 
	    << pairs.count(15)
	    << " pairs with key 15" << std::endl << std::endl;
  //pairs[15] = 12.5;
  // More insertions
  pairs.insert(MMID::value_type(30, 111.11));
  pairs.insert(MMID::value_type(10, 22.22));
  pairs.insert(MMID::value_type(25, 33.333));
  pairs.insert(MMID::value_type(20, 9.345));
  pairs.insert(MMID::value_type(5, 77.54));
  std::cout << "Multimap pairs contains:\nKey\tValue" << std::endl;
  //pairs[5] = 12.3;
  // Iterate over the map and print out the information.
  for (MMID::const_iterator iter = pairs.begin(); iter != pairs.end(); ++iter)
    std::cout << iter->first << '\t'  << iter->second << std::endl;
  
  std::cout << std::endl;
  return 0;
}

/*
There are currently 0 pairs with key 15 in the multimap

After inserts, there are 2 pairs with key 15

Multimap pairs contains:
Key     Value
5       77.54
10      22.22
15      2.7
15      99.3
20      9.345
25      33.333
30      111.11
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
