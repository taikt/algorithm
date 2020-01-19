// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {
            return (!l1)? l2: l1;
        }
        ListNode *head, *p;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        p = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            } else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        if (l1) p->next = l1;
        if (l2) p->next = l2;

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
    // Input: 1->2->4, 1->3->4
    // Output: 1->1->2->3->4->4

    freopen("lc_21.inp","r",stdin);
    freopen("lc_21.out","w",stdout);
    // input
    // n: so thanh phan list 1
    // 1 2 4
    // m: so thanh phan list 2
    // 1 3 4
    ListNode* l1=nullptr;
    ListNode* l2=nullptr;
    int n, m, val;
    scanf("%d\n",&n);
    for (int i=0; i<n;i++) {
        scanf("%d",&val);
        ListNode* node = new ListNode(val);
        if (l1 == nullptr) {
            l1 = node;
        } else {
            ListNode *temp = l1;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = node;
        }
    }

    scanf("%d\n",&m);
    for (int i=0; i<m;i++) {
        scanf("%d",&val);
        ListNode* node = new ListNode(val);
        if (l2 == nullptr) {
            l2 = node;
        } else {
            ListNode *temp = l2;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = node;
        }
    }

    Solution sol;
    sol.printList(l1);
    sol.printList(l2);
    ListNode *merged_list = sol.mergeTwoLists(l1,l2);
    sol.printList(merged_list);

    return 0;
}
