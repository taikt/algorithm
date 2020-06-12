// Example program
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    // vector
    vector<int> first;// (4,100);
    first.assign(7,10); // assign 7 first elements with value of 10
    // first = 10 10 10 10 10 10 10

    for (int i = 1; i<4; i++)
    	first.push_back(i);
    // first = 10 10 10 10 10 10 10 1 2 3 
    
    for (vector<int>::iterator it = first.begin(); it != first.end(); ++it)
    	cout <<' '<<*it;

    cout<<endl;

}