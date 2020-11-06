/** NegatorExample.cpp
 * Authors: D. Schmidt
 * Contributors: J. Adams
 * Description: A program that that uses a Negator functor
 */

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>

int main() {
  std::vector<int> vect1;
  std::ostream_iterator<int> output(std::cout, " ");

  // Place four items into the vector
  vect1.push_back (1); 
  vect1.push_back (2); 
  vect1.push_back (3); 
  vect1.push_back (4);
  std::cout << "vect 1: ";
  std::copy (vect1.begin(), vect1.end (), output);
  std::cout << std::endl;

  // Store the items from vect1 that are greater than 3 into vect2.
  std::vector<int> vect2;
  std::remove_copy_if (vect1.begin(), vect1.end(), back_inserter (vect2),
		       std::bind2nd (std::greater<int> (), 3));
  std::cout << "vect2 :";
  std::copy (vect2.begin(), vect2.end (), output);
  std::cout << std::endl;

  // Store the items from vect1 that are not greater then 3 in vect3
  std::vector<int> vect3;
  std::remove_copy_if (vect1.begin(), vect1.end(), std::back_inserter (vect3),
		       std::not1 (std::bind2nd (std::greater<int> (), 3)));
  std::cout << "vect3 : ";
  std::copy (vect3.begin(), vect3.end (), output);
  std::cout << std::endl;

  return 0;
}


/***************** Output
vect: 1 2 3 4
vect2: 1 2 3
vect3: 4

*/
