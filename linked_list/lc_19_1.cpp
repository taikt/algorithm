#include <bits/stdc++.h>
using namespace std;

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL;
        ListNode *pre = head, *cur = head;

        for (int i = 0; i < n; ++i) cur = cur->next;
        // sau khi move n steps, neu cur is empty => n la length cua link list
        // ==> can remove head cua link list
        if (!cur) return head->next;
        while (cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }

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
    freopen("lc_19.inp","r",stdin);
    freopen("lc_19.out","w",stdout);

    ListNode* l=nullptr;
    int n,val;
    scanf("%d\n",&n);
    string st;
    getline(cin,st);
    stringstream str(st);

    while(str>>val) {
        scanf("%d",&val);
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
    cout<<"original list\n";
    su.printList(l);
    su.removeNthFromEnd(l,n);
    cout<<"result list\n";
    su.printList(l);

    return 0;
}
