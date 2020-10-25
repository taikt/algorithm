#include <bits/stdc++.h>
#include "node.h"
using namespace std;

// priority queue
class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode*& a, ListNode*& b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > q(cmp);
        for (auto node : lists) {
            if (node) q.push(node);
        }
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            cur->next = t;
            cur = cur->next;
            if (cur->next) q.push(cur->next);
        }
        return dummy->next;
    }
};

// devide and conque
#define FOR(i,a,b) for(int i=a; i<b; i++)

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int n = lists.size();
        // n =5
        // k=3
        // i=0,1
        // list[0]=merge(list[0],list[3])
        // list[1]=merge(list[1],list[4])
        // list[2 unchanged
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy->next;
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
/*
3
1 4 5
1 3 4
2 6
*/
    freopen("lc_23.inp","r",stdin);
    freopen("lc_23.out","w",stdout);
    int n;
    scanf("%d\n",&n);
    vector<ListNode*> lists(n);
    int val;
    string st;

    FOR(i,0,n) {
        getline(cin,st);
        stringstream str(st);
        //lists[i] == nullptr; // don't need this, all lists[i] is auto pointed to NULL
        while(str>>val) {
            ListNode* node = new ListNode(val);
            if (lists[i] == nullptr) {
                lists[i] = node;
            } else {
                ListNode *temp = lists[i];
                while (temp->next != nullptr) temp = temp->next;
                temp->next = node;
            }
        }
    }

    Solution su;
    ListNode* out = su.mergeKLists(lists);
    su.printList(out);

    return 0;
}
