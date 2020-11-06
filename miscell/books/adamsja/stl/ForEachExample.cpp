/**
 * Filename: ForEachExample.cpp
 * Author: Douglas Schmidt
 * Author: Julie A. Adams
 * Description: A test program to demonstrate the capabilities of for_each()
 */

#include <iostream>
#include <algorithm>

template<class T> 
struct print {
  print (std::ostream &out): os_(out), count_(0) {}
  void operator() (T x) { os_ << x << ' '; ++count_; };
  std::ostream &os_;
  int count_;
};

int main ()
{
  int arry[] = {1, 4, 2, 8, 5, 7};

  const int N = sizeof(arry) / sizeof(int);

  // for_each() returns function object after being aplied to each element
  print<int> f = std::for_each(arry, arry + N, print<int>(std::cout));
  std::cout << std::endl << std::endl << f.count_ << " objects printed." << std::endl;

  return 0;
}

/************* OUTPUT *********************
1 4 2 8 5 7

6 objects printed.
*/
