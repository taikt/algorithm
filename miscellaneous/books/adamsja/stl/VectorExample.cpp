/**
 * Filename: VectorExample.cpp
 * Author: Doug Schmidt
 * Author: Julie A. Adams
 * Description: The program takes a number of items and stores them into the 
 *              vector. After storing the item in the vector, the item is printed
 *             from the vector.
 */

#include <iostream>
#include <vector>
#include <string>

int main (int argc, char *argv[])
{
  // Define a vector of strings
  std::vector <std::string> projects;

  // Output the name of the executable to run this program.
  std::cout << "program name:" << argv[0] << std::endl;

  // Push the list of command line items into the vector and output them.
  for (int i = 1; i < argc; ++i) {
    projects.push_back (argv [i]);
    std::cout << projects [i - 1] << std::endl;
  }
  return 0;
}
