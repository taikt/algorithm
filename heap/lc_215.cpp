// https://leetcode.com/problems/kth-largest-element-in-an-array/
#include <bits/stdc++.h>
#include <queue>
using namespace std;
// O(Nlogk)
// voi heap size k, add 1 thanh phan: O(log(k))

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap; // top is min
        //priority_queue<int> max_heap; // by default, queue is a max heap, top is max
        for (auto a:nums) {
            min_heap.push(a);
            if (min_heap.size() >k)
                min_heap.pop();
        }

        int res = 0;
        if (!min_heap.empty()) res = min_heap.top();
        return res;
    }
};

int main() {
    freopen("lc_215.inp","r",stdin);
    freopen("lc_215.out","w",stdout);
    int n,k;
    scanf("%d %d\n",&n,&k);
    vector<int> v(n);
    for (int i=0; i<n;i++)
        scanf("%d ",&v[i]);

    Solution so;
    cout<<so.findKthLargest(v,k);

    return 0;
}
