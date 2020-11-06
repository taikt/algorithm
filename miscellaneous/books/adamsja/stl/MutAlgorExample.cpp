/**
 * Filename: MutAlgorSearchSortExample.cpp
 * Author: Julie A. Adams
 * Description: A test program to demonstrate the capabilities of various
 *              STL mutating algorithms. Carefully study the output in order
 *              to fully understand what is happening. Things are not always
 *              what they appear to be.
 */

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

char nextLetter();
bool equalA(char);

int main() {
  // instantiate a vector of characters
  vector<char> charVec(10);
  ostream_iterator<char> output(cout, " ");
  vector<char>::iterator iter;

  // Fill the vector with the character 5
  fill(charVec.begin(), charVec.end(), '5');
  cout << "CharVec after filling with 5s: " << endl;
  copy(charVec.begin(), charVec.end(), output);
  cout << endl << endl;

  /* Fill the first five positions in the vector with the character A,
     effectively overwriting the first five characters. */
  fill_n(charVec.begin(), 5, 'A');
  cout << "CharVec after filling five elements: " << endl;
  copy(charVec.begin(), charVec.end(), output);
  cout << endl << endl;
  
  // Remove the character A from the vector, return a new end iterator
  iter = remove(charVec.begin(), charVec.end(), 'A');
  cout << "CharVec after removing all As: " << endl;
  copy(charVec.begin(), iter, output);
  cout << endl << endl;

  // Generate and insert the letters A - J. 
  generate(charVec.begin(), charVec.end(), nextLetter);
  cout << "CharVec after generating letters A-J: " << endl;
  copy(charVec.begin(), charVec.end(), output);
  cout << endl << endl;

  // Generate and insert the next five characters
  generate_n(charVec.begin(),5, nextLetter);
  cout << "CharVec after generating letters K-O for the first five elements: " 
       << endl;
  copy(charVec.begin(), charVec.end(), output);
  cout << endl << endl;

  charVec.push_back('A');
  charVec.push_back('A');
  
  // remove_if returns a new iter pointing to the new end of the vector but...
  iter = remove_if(charVec.begin(), charVec.end(), equalA);
  cout << "CharVec after removing A's using iter: " << endl;
  copy(charVec.begin(), iter, output);
  cout << endl << endl;

  // remove_if doesn't actually remove the old values from the vector
  cout << "CharVec after removing A's using end(): " << endl;
  copy(charVec.begin(), charVec.end(), output);
  cout << endl << endl;
 
  charVec.push_back('A');
  charVec.push_back('A');
  // The output will include old values
  cout << "CharVec after adding two A's with end(): " << endl;
  copy(charVec.begin(), charVec.end(), output);
  cout << endl << endl;
  
  // the output will only print the items prior to push, iter is not updated.
  cout << "CharVec after adding two A's with iter: " << endl;
  copy(charVec.begin(), iter, output);
  cout << endl << endl;

  // the output will print the proper values
  cout << "CharVec after adding two A's with 'iter + 2': " << endl;
  copy(charVec.begin(), iter + 2, output);
  cout << endl << endl;

  // Note that the random shuffle doesn't shuffle the two A's that were 
  // "removed" by remove_if
  random_shuffle(charVec.begin(), charVec.end());
  cout << "CharVec after the random shuffle: " << endl;
  copy(charVec.begin(), charVec.end(), output);
  cout << endl << endl;

  /* Copies the values of the elements in the range [first,last) to the range 
   * positions beginning at result, except for the elements that compare 
   * equal to value, which are not copied.
   */
  // What happens if we remove '+ 5'?
  remove_copy(charVec.begin(), charVec.end()+ 5,  charVec.begin(), 'A');
  cout << "CharVec after remove_copy: " << endl;
  copy(charVec.begin(), charVec.end(), output);
  cout << endl << endl;

  charVec.push_back('A');
  charVec.push_back('A');
  cout << "CharVec after adding two A's: " << endl;
  copy(charVec.begin(), charVec.end(), output);
  cout << endl << endl;

  // Replace the character A with the character Z
  replace_if(charVec.begin(), charVec.end(), equalA, 'Z');
  cout << "CharVec after replacing A's with Z's: " << endl;
  copy(charVec.begin(), charVec.end(), output);
  cout << endl << endl;

  return 0;
}

char nextLetter() {
  /* Letter must be static so that it maintains the proper value of letter
     when the function exits. */
  static char letter = 'A';
  return letter++;
}

bool equalA(char x) {
  return x == 'A';
}


/*************** OUTPUT ********
CharVec after filling with 5s:
5 5 5 5 5 5 5 5 5 5

CharVec after filling five elements:
A A A A A 5 5 5 5 5

CharVec after removing all As:
5 5 5 5 5

CharVec after generatir letters A-J:
A B C D E F G H I J

CharVec after generating letters K-O for he first five elements:
K L M N O F G H I J

CharVec after removing A's using iter:
K L M N O F G H I J

CharVec after removing A's using end():
K L M N O F G H I J A A

CharVec after adding A's with end():
K L M N O F G H I J A A A A

CharVec after adding A's with iter:
K L M N O F G H I J 

CharVec after adding A's with 'iter + 2':
K L M N O F G H I J A A

CharVec after the random_shuffle: (example)
A L J M K A H N O G I F A A

CharVec after remove_copy:
L J M K H N O G I F

CharVec after adding two A's:
L J M K H N O G I F          A A

CharVec after replacing A's with Z's:
L J M K H N O G I F          Z Z

*/
