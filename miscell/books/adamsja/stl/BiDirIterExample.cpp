/** BiDirIterExample.cpp
 * Authors: Nyhoff
 * Contributors: J. Adams
 * Description: A program that creates a list and demonstrates the use of a 
 *              bi-directional iterator
 */
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
  list<int> bList(4, 111);
  int arry[] = {2, 22, 222, 2222};
  
  // Use various insert methods to put items into the list
  
  list<int>::iterator anIter;
  
  // Set the iterator and advance it before inserting an item into the list
  anIter = bList.begin();
  anIter++;
  anIter++;
  cout << endl << "Insert 66666 into bList " << endl;
  bList.insert(anIter, 66666);
  copy(bList.begin(), bList.end(), ostream_iterator<int> (cout, " "));
  cout << endl;

  // Insert three items into the list at the current iterator position
  cout << endl << "Insert three 555's into bList " << endl;
  bList.insert(anIter, 3 ,555);
  copy(bList.begin(), bList.end(), ostream_iterator<int> (cout, " "));
  cout << endl;

  // Insert the values in arry into the list
  cout << endl << "Insert arry into bList " << endl;
  bList.insert(anIter, arry, arry + 3);
  copy(bList.begin(), bList.end(), ostream_iterator<int> (cout, " "));
  cout << endl;

  // Let's put some more items into the list
  cout << endl << "Insert 111 and 888 into bList " << endl;
  bList.push_back(888);
  bList.push_front(111);
  copy(bList.begin(), bList.end(), ostream_iterator<int> (cout, " "));
  cout << endl;

  // reset anIter to the front of the list
  anIter = bList.begin();
  // Manipulate the iterator demonstrating it's bidirectional capabilities
  anIter++;
  anIter++;
  --anIter;
  anIter++;
  anIter++;
  anIter++;
  anIter--;

  // Remove the item the iterator currently points too from the list
  cout << endl << "Remove 66666 from bList " << endl;
  bList.erase(anIter);
  copy(bList.begin(), bList.end(), ostream_iterator<int> (cout, " "));
  cout << endl;
  
  
  
  return 0;
}

/************** The program output ******************

Insert 66666 into bList
111 111 66666 111 111

Insert three 555's into bList
111 111 66666 555 555 555 111 111

Insert 111 and 888 into bList
111 111 111 66666 555 555 555 111 111 888

Remove 66666 from bList
111 111 111 555 555 555 111 111 888

*/
