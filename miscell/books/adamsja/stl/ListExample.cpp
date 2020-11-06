/**
 * Filename: ListExample.cpp
 * Author: Doug Schmidt
 * Author: Julie A. Adams
 */

#include <list>
#include <iostream>
#include <iterator>
#include <string>


int main() {
  // Define a list of strings
  std::list<std::string> aList;
  
  // Place strings into the list
  aList.push_back("banana");
  aList.push_front("apple");
  aList.push_back("carrot");
  
  // Create an ostream iterator for outputing the list of strings
  std::ostream_iterator<std::string> out_it (std::cout, "\n");
  
  // Output the list in order
  std::cout << "List in order" << std::endl;
  std::copy (aList.begin(), aList.end(), out_it);
 
  // Output the list in reverse order
  std::cout << std::endl << "List in reverse order" << std::endl;
  std::reverse_copy (aList.begin(), aList.end(), out_it);

  // Output the list using the standard copy. Note that the list has been
  // reversed.
  std::cout << std::endl << "List after reverse_copy" << std::endl;
  std::copy (aList.rbegin(), aList.rend(), out_it);

  return 0;
}
