/**
 * Filename: SearchSortExample.cpp
 * Author: Julie A. Adams
 * Description: A test program to demonstrate the capabilities of various
 *              STL search and sort algorithms
 */

#include <iostream>
#include <vector>
#include <string>
#include <iterator>

// Helper functions
bool greater30(int value);
bool descending (int rhs, int lhs);

int main ()
{
  const int SIZE = 10;
  int arry[SIZE] = {1, 12, 67, 5, 40, 22, 111, 222, 70, 50};
  // Create a vector containing the values in arry
  std::vector<int> nums(arry, arry + SIZE);
 
  // Place some additional values into the vector
  nums.push_back(10);
  nums.push_back(40);
  nums.push_back(30);
  nums.push_back(20);
  nums.push_back(50);
  nums.push_back(10);

  // Define an output iterator
  std::ostream_iterator<int> output(std::cout, " ");

  // Output the current vector
  std::cout << "Vector contains : ";
  std::copy(nums.begin(), nums.end(), output);

  // Define an iterator to hold the position return from the algorithms below
  std::vector<int>::iterator location;
  
  // return an iterator to the position of the value 20 in the vector, if it exists
  location = std::find(nums.begin(), nums.end(), 20);

  // Print out either where the value was found or that it was not found.
  if (location != nums.end())
    std::cout << std::endl << std::endl << "Found 20 at location: " << 
      (location - nums.begin()) << std::endl << std::endl;
  else
    std::cout << std::endl << "20 not found in vector" << std::endl << std::endl;

  // Find the location of a value in the vector that is greater than 30, 
  // if it exists
  location = std::find_if(nums.begin(), nums.end(), greater30);
  
  // Output the value greater than 30 and its location, if it exists
  if (location != nums.end())
    std::cout << "The first value greater than 30 is " << *location << 
      " found at location " << (location - nums.begin()) << std::endl << std::endl;
  else
    std::cout << std::endl << "No values greater than 30 found in vector" << std::endl << std::endl;

  // Sort and output the vector using the basic sort algorithm
  std::sort(nums.begin(), nums.end());
  std::cout << "The vector after sorting : " << std::endl;
  std::copy(nums.begin(), nums.end(), output);

  // Sort the vector using a user defined compartor and output the vector.
  std::sort(nums.begin(), nums.end(), descending);
  std::cout << std::endl << std::endl << "The vector after sorting in descending order: " << std::endl;
  std::copy(nums.begin(), nums.end(), output);
  std::cout << std::endl;
  
  return 0;
}

/**
 * greater30
 * Description: A function to test if a value is greater than 30
 */
bool greater30( int value ) {
  return value > 30;
}

/**
 * descending
 * Description: A function to test if the rhs side value is less than the 
 *              lhs value.
 */
bool descending (int rhs, int lhs) {
  return rhs > lhs;
}

/************* OUTPUT *********************

Vector contains: 1 12 67 5 40 22 111 222 70 50 10 40 30 20 50 10

Found 20 at location: 13

The first value greater than 30 is 67 found at location 2

The vector after sorting:
1 510 10 12 20 22 30 40 40 50 50 67 70 111 222

The vector after sorting in descending order:
222 111 70 67 50 50 40 40 30 22 20 12 10 10 5 1

*/
