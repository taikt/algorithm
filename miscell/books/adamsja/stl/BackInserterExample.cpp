/** BackInserterExample.cpp
 * Authors: Deitel & Deitel
 * Contributors: J. Adams
 * Description: A program that that uses back_inserter()
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
  const int SIZE = 10;
  int arry[SIZE] = {1, 3, 5, 7, 9, 1, 3, 5, 7, 9};
  std::vector<int> vect(arry, arry + SIZE);

  std::ostream_iterator<int> output(std::cout, " ");

  // Simply output the contents of the vector.
  std::cout << "vect contains: "; 
  std::copy(vect.begin(), vect.end(), output);
  std::cout << std::endl;

  //Sort two sorted sequences of elements in the same container
  std::inplace_merge( vect.begin(), vect.begin() + 5, vect.end());
  std::cout << "vect after inplace_merge: ";
  std::copy(vect.begin(), vect.end(), output);
  std::cout << std::endl;

  // make a copy of the unique elements in vect and use back_inserter to put
  // the elements into results because memory has not been preallocated for 
  // the vector elements.
  std::vector<int> results;
  std::unique_copy(vect.begin(), vect.end(), std::back_inserter(results));
  std::cout << "results contains: ";
  std::copy(results.begin(), results.end(), output);
  std::cout << std::endl;
 
  // make a reverse copy of the elements in vect, store into results2 using
  // back_inserter because did not preallocate memory.
  std::vector<int> results2;
  std::reverse_copy(vect.begin(), vect.end(), std::back_inserter(results2));
  std::cout << "results2 contains: ";
  std::copy(results2.begin(), results2.end(), output);
  std::cout << std::endl;

  return 0;
}

/************** The program output ******************

vect contains: 1 3 5 7 9 1 3 5 7 9 
vect after inplace_merge: 1 1 3 3 5 5 7 7 9 9 
results contains: 1 3 5 7 9
results2 contains: 9 9 7 7 5 5 3 3 1 1 

*/
