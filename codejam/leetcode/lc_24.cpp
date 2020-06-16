// g++ lc_24.cpp

#include <bits/stdc++.h>
#include "node.h"
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       if (head == NULL) return NULL;
        ListNode* temp = head->next;
        if (temp == NULL) return head;
        if (temp->next == NULL) {
        	temp->next = head;
        	head->next = NULL;
        	return temp;
        }
        head->next = swapPairs(temp->next);
        temp->next = head;
       	return temp;
    }
};

int main() {
	vector<int> l1 = {1,4,5,9,8,7};
	ListNode* list=vectorToList(l1);
	printList(list);
	Solution a;
	list = a.swapPairs(list);
	printList(list);

	return 0;
}