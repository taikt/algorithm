/** PtrFunExample.cpp
 * Authors: D. Schmidt
 * Contributors: J. Adams
 * Description: A program that that uses a ptr_fun functor
 */

#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

int main () {
  std::ostream_iterator<char*> output(std::cout, " ");
  std::vector<char *> vect;

  vect.push_back ("One"); 
  vect.push_back ("Two"); 
  vect.push_back ("Three"); 
  vect.push_back ("Four");
  
  std::cout << "Sequence contains: ";
  std::copy (vect.begin (), vect.end (), output );
  std::cout << std::endl << "Searching for Three." << std::endl;

  // Use Negator and bind2nd to search the vector using strcmp to find the 
  // string "Three" and return the iterator. 
  std::vector<char *>::iterator it = std::find_if (vect.begin (), 
							vect.end (),
							std::not1 (std::bind2nd (std::ptr_fun (std::strcmp), 
							"Two")));
  if (it != vect.end ()) {
    std::cout << "Found it! Here is the rest of the story: ";
    std::copy (it, vect.end (), output);
  }
  std::cout << std::endl;

  return 0;
}

/************** Output
Sequence contains: One Two Three Four
Search for Three.
Fount it! Here is the rest of the story: Three Four
*/
