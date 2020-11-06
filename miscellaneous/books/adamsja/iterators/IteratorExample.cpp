/* File: IteratorExample.cpp
 * Authors: Doug Schmidt
 * Contributors: J. Adams
 * Description: Testing StandardTemplate Library iterator
 */

#include <iostream>
#include <vector>
#include <string>
#include <iterator>

int main (int argc, char *argv[]) {

  std::vector <std::string> projects; // Names of the projects

  for (int i = 1; i < argc; ++i)
    projects.push_back (std::string (argv [i]));
  
  for (std::vector<std::string>::iterator j = projects.begin ();
       j != projects.end (); ++j)
    std::cout << *j << std::endl;
  
  return 0;
}

/********** OUTPUT *************

//execute the program at the command line with:
IteratorExample Julie John Bruce Judy Tom Joy

// the program output is:
Julie
John
Bruce
Jude
Tom
Joy
**/
