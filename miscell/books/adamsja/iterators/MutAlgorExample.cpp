/**
 * Filename: MutAlgorSearchSortExample.cpp
 * Author: Julie A. Adams
 * Description: A test program to demonstrate the capabilities of various
 *              STL mutating algorithms. Carefully study the output in order
 *              to fully understand what is happening. Things are not always
 *              what they appear to be.
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
  // instantiate a vector of characters
  std::vector<char> charVec(10), charVec2(10);
  std::ostream_iterator<char> output(std::cout, " ");
  std::vector<char>::iterator iter;

  // Fill the vector with the character 5
  std::fill(charVec.begin(), charVec.end(), '5');
  std::cout << "CharVec after filling with 5s: " << std::endl;
  std::copy(charVec.begin(), charVec.end(), output);
  std::cout << std::endl << std::endl;

  // Fill the vector with the character D
  std::fill(charVec2.begin(), charVec2.end(), 'D');
  std::cout << "CharVec2 after filling with Ds: " << std::endl;
  std::copy(charVec2.begin(), charVec2.end(), output);
  std::cout << std::endl << std::endl;

  std::swap(charVec, charVec2);
  std::cout << "CharVec after swap: " << std::endl;
  std::copy(charVec.begin(), charVec.end(), output);
  std::cout << std::endl << std::endl;  
  std::cout << "CharVec2 after swap: " << std::endl;
  std::copy(charVec2.begin(), charVec2.end(), output);
  std::cout << std::endl << std::endl;

  // using default comparison:
  if (std::equal(charVec.begin(), charVec.end(), charVec2.begin()))
    std::cout << "The contents of both vectors are equal." << std::endl;
  else
  std::cout << "The contents of both vectors differ." << std::endl;
  
  charVec[5] = 'Z';
  std::cout << std::endl << "CharVec after Z change: " << std::endl;
  std::copy(charVec.begin(), charVec.end(), output);
  std::cout << std::endl << std::endl;  
  iter = charVec.begin();
  std::advance(iter, 5);
  std::cout << "The sixth element is: " << *iter << std::endl;  
  return 0;
}
