/** MemfunRefExample.cpp
 * Authors: D. Schmidt
 * Contributors: J. Adams
 * Description: A program that that uses mem_fun_ref
 */

#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

class WrapInt {
public:
  WrapInt (): val_ (0) {}
  WrapInt(int x): val_ (x) {}
  void showval() { std::cout << val_ << " "; }
  bool is_prime() {				
    bool flag = true;
    for (int i = 2; i <= (val_ / 2); i++)
      if ((val_ % i) == 0)
	flag = false;
    return flag;
  }
private:
  int val_;
};

int main() {
  std::vector<WrapInt> vect (10);
  
  // Create and store 10 WrapInts into the vector
  for (int i = 0; i < 10; i++)
    vect[i] = WrapInt (i + 1);
  
  // Output the WrapInt objects stored in the vector
  std::cout << "Sequence contains: ";
  std::for_each (vect.begin (), vect.end (), std::mem_fun_ref (&WrapInt::showval));
  std::cout << std::endl;
 
  // create an iterator that points to the last item in vect after all
  // WrapInt objects containing prime numbers are removed from the vector.
  std::vector<WrapInt>::iterator end_p = 
    std::remove_if (vect.begin(), vect.end(), std::mem_fun_ref (&WrapInt::is_prime));
  std::cout << "Sequence after removing primes: ";
  std::for_each (vect.begin (), end_p, std::mem_fun_ref (&WrapInt::showval));
  std::cout << std::endl;

 return 0;
}

/********* output
Sequence contains: 1 2 3 4 5 6 7 8 9 10
Sequence after removing primes: 4 6 8 9 10
*/
