/** BinderExample.cpp
 * Authors: D. Schmidt
 * Contributors: J. Adams
 * Description: A program that that uses a binder functor
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cstdlib>
#include <ctime>

int main (int argc, char *argv[]) {
  std::srand (time(0));
  std::ostream_iterator<int> output(std::cout, " ");
  std::vector<int> vect, vect2 (10, 20);

  // Place ten random integers into vect where time(0) is the seed for the 
  // random number generator.
  std::generate_n (std::back_inserter (vect), 10, std::rand);

  // Transform vect by calculating vect item modulus vect2 item and store in vect
  std::transform (vect.begin (), vect.end (), vect2.begin (), vect.begin (), 
		  std::modulus<int>());
  std::cout << "vect after transform: ";
  std::copy(vect.begin(), vect.end(), output);
  std::cout << std::endl;
  
  int factor = 2;

  // Transform vect starting in the first position by multiply each item
  // by 2. The bind2nd ensures that multiplies is called with 2.
  std::transform (vect.begin (), vect.end (), vect.begin(), 
		  std::bind2nd (std::multiplies<int> (), factor));
  std::cout << "vect after second transform: ";
  std::copy(vect.begin(), vect.end(), output);
  std::cout << std::endl;

  return 0;
}


/***************** Output
vect after transform: 4 11 1 6 11 15 13 12 0 10
vect after second transform: 8 22 2 12 22 30 26 24 0 20

*/
