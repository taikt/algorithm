/**
 * Filename: DequeExample.cpp
 * Author: Doug Schmidt
 * Author: Julie A. Adams
 */

#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>

int main() {

  // Create a deque of ints
  std::deque<int> aDeck;

  // Push an item onto the back and an item onto the front
  aDeck.push_back(3);
  aDeck.push_front(1);
  
  // Output the contents of aDeck
  std::copy (aDeck.begin(), aDeck.end(), 
	     std::ostream_iterator<int> (std::cout, " "));
  std::cout << std::endl;

  // Insert an item into the middle of the deque
  aDeck.insert (aDeck.begin() + 1, 2);

  // Output the contents of aDeck
  std::copy (aDeck.begin(), aDeck.end(),
	     std::ostream_iterator<int> (std::cout, " "));
  std::cout << std::endl;

  // Assign a value to a particular element in aDeck
  aDeck[2] = 0;
  
  // Output the contents of aDeck
  std::copy (aDeck.begin(), aDeck.end(),
	     std::ostream_iterator<int> (std::cout, " "));
  std::cout << std::endl;

  return 0;
}
