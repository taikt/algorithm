/**
 * Filename: FuncObjExample.cpp
 * Author: Douglas Schmidt
 * Author: Julie A. Adams
 * Description: A test program to demonstrate STL Function objects
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <iterator>

int main (int argc, char *argv[])
{
  std::vector<std::string> projects;
  std::ostream_iterator<std::string> output( std::cout, " " );

  for (int i = 0; i < argc; ++i ) {
    projects.push_back(std::string(argv[i]));
  }

  std::copy( projects.begin(), projects.end(), output);
  std::cout << std::endl << std::endl;

  // Use the STL Functor greater to sort the vector
  std::sort(projects.begin(), projects.end(), std::greater<std::string>());
  std::copy(projects.begin(), projects.end(), output);
  std::cout << std::endl << std::endl;

  int numbers[]={20,40,50,10,30};
  std::sort (numbers, numbers+5, std::greater<int>() );
  for (int i=0; i<5; i++)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;

  return 0;
}

/************* OUTPUT *********************

*/
