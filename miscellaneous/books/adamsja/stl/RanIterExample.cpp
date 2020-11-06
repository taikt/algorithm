/**
 * Filename: RanIterExample.cpp
 * Author: Doug Schmidt
 * Author: Julie A. Adams
 * Description: An example of using a random access iterator
 */

#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {

  // Create a deque of ints
  deque<int> aDeck;

  // Define an iterator
  deque<int>::iterator iter;

  // Push an item onto the back and two items onto the front
  aDeck.push_back (3);
  aDeck.push_front (1);
  aDeck.push_front (0);
  
  /* Set the iterator to the beginning of the Deque and manipulate it before
     inserting an item into the Deque*/
  iter = aDeck.begin();
  iter += 2;
  aDeck.insert(iter, 5);

  // Output the contents of aDeck
  copy (aDeck.begin (), aDeck.end (), 
	ostream_iterator<int> (cout, " "));
  cout << endl << endl;

  // Insert an item into the middle of the deque
  aDeck.insert (aDeck.begin () + 2, 2);

  // Output the contents of aDeck
  copy (aDeck.begin (), aDeck.end (),
	ostream_iterator<int> (cout, " "));
  cout << endl << endl;

  /* Set the iterator to the end of the Deque and manipulate it before
     inserting an into into the Deque */
  iter = aDeck.end();
  iter -= 3;
  aDeck.insert(iter, 9);

  // Output the contents of aDeck
  copy (aDeck.begin (), aDeck.end (),
	ostream_iterator<int> (cout, " "));
  cout << endl << endl;

  // Assign a value to a particular element in aDeck
  aDeck[2] = 0;
  
  // Output the contents of aDeck
  copy (aDeck.begin (), aDeck.end (),
	ostream_iterator<int> (cout, " "));
  cout << endl;

  return 0;
}

/*********** OUTPUT ***********
0 1 5 3

0 1 2 5 3

0 1 9 2 5 3

0 1 0 2 5 3

*/
