/**
 * Filename: TransforExample2.cpp
 * Author: Douglas Schmidt
 * Author: Julie A. Adams
 * Description: A test program to demonstrate the capabilities of transform()
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <iterator>

int main ()
{
  std::ostream_iterator<float> output (std::cout, " ");
  // A vector of five floats initialized to 1.0
  std::vector<float> vect(5, 1);
  
  /* Assigns to every element in the range starting at vect.begin (the third 
   * parameter) the partial sum of the corresponding elements in the range 
   * vect.begin() to vect.end()
   */
  std::partial_sum(vect.begin(), vect.end(), vect.begin());

  std::copy(vect.begin(), vect.end(), output);
  std::cout << std::endl;

  /* multiple every element from vect.begin() to vect.edu() by an item pointed
   * at by a forward iterator (in this case starting at vect.begin()) and store
   * it in the container pointed to by vect.begin(). In other words, multiple
   * each item in the vector by itself and store the result back into the 
   * current position before moving to the next item in the vector.
   */
  std::transform(vect.begin(), vect.end(), vect.begin(), vect.begin(), 
		 std::multiplies<float>());
  std::copy(vect.begin(), vect.end(), output);
  std::cout << std::endl;

  /* divide every element from vect.begin() to vect.edu() and store
   * the result in the container pointed to by vect.begin(). bind2nd binds the 
   * second operator to the value 3 and each item in the vector is divided by 
   * 3. 
   */
  std::transform(vect.begin(), vect.end(), vect.begin(), std::bind2nd(std::divides<float>(), 3));
  
  std::copy(vect.begin(), vect.end(), output);
  std::cout << std::endl;

  return 0;
}

/************* OUTPUT *********************
1 2 3 4 5

1 4 9 16 25

0.33333 1.33333 3 5.33333 8.33333
*/
