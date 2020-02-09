#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<b; i++)
/**
 * Definition for singly-linked list.
 */


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    void printList(ListNode* l) {
        ListNode *temp = l;

        while (temp != nullptr) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
};

int main() {
    freopen("link_list.inp","r",stdin);
    freopen("link_list.out","w",stdout);

    ListNode* l=nullptr;
    int val;
    string st;
    getline(cin,st);
    stringstream str(st);

    while(str>>val) {
        //scanf("%d",&val);
        ListNode* node = new ListNode(val);
        if (l == nullptr) {
            l = node;
        } else {
            ListNode *temp = l;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = node;
        }
    }

    Solution su;
    su.printList(l);

    return 0;
}
