/*
remove duplicates from unsorted linked list.
method: use hash table
duyet qua link list, neu phan tu chua co trong bang hash, add vao list.
neu phan tu da co trong bang hash, remove tu list.
time: O(N)
*/
#pragma once
#include <bits/stdc++.h>
#include "node.h"
using namespace std;

template <typename T>
void removeDups(SinglyLinkedNode<T>* head){
    SinglyLinkedNode<T>* slowRunner = head;
    if (slowRunner == nullptr || slowRunner->getNext() == nullptr) return;  // a list of length 0 or 1 cannot have dups
    SinglyLinkedNode<T>* fastRunner = slowRunner->getNext();
    std::unordered_map<T, bool> hashTable;
    hashTable[slowRunner->getValue()] = true;
    while (fastRunner != nullptr){
        if (hashTable.count(fastRunner->getValue())){
            slowRunner->setNext(fastRunner->getNext());
            fastRunner->setNext(nullptr);
            delete fastRunner;
            fastRunner = slowRunner->getNext();
        } else {
            hashTable[fastRunner->getValue()] = true;
            slowRunner = fastRunner;
            fastRunner = fastRunner->getNext();
        }
    }
}
