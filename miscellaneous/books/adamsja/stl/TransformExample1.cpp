/**
 * Filename: TransforExample1.cpp
 * Author: Douglas Schmidt
 * Author: Julie A. Adams
 * Description: A test program to demonstrate the capabilities of transform()
 */

#include <iostream>
#include <string>
#include <functional>
#include <ctype.h>

class to_lower {
public:
  // a function object (functor)
  char operator() (char c) const {
    return std::isupper(c) ? std::tolower(c) : c;
  }
};

// Transform the string from upper case to lower case
std::string lower (const std::string &str) {
  std::string lc(" ");
  std::transform (str.begin(), str.end(), back_inserter(lc), to_lower());

  return lc;
}

int main ()
{
  std::string s("HELLO");

  std::cout << s << std::endl;

  s = lower(s);
  
  std::cout << s << std::endl;

  return 0;
}

/************* OUTPUT *********************

HELLO

hello
*/
