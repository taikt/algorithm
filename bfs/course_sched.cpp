/*
 * g++ course_sched.cpp --std=c++11
 * https://github.com/grandyang/leetcode/issues/207
 *
 */

#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses);
        for (auto a : prerequisites) {
            printf("a[0]=%d, a[1]=%d\n",a[0],a[1]);
            graph[a[1]].push_back(a[0]);
            ++in[a[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (auto a : graph[t]) {
                --in[a];
                if (in[a] == 0) q.push(a);
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] != 0) return false;
        }
        return true;
    }

};

int main() {
    int V;
    V = 2;
    vector<vector<int>> prerequisites = {
        {1,0},
        {0,1}
    };
    
    Solution anws;    
    if (anws.canFinish(V,prerequisites)) printf("can finish all courses\n");
    else printf("cannot finish all courses\n");

	return 0;
}
