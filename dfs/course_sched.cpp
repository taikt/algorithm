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
        vector<int> visit(numCourses);
        for (auto a : prerequisites) {
            graph[a[1]].push_back(a[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!canFinishDFS(graph, visit, i)) return false;
        }
        return true;
    }
    bool canFinishDFS(vector<vector<int>>& graph, vector<int>& visit, int i) {
        if (visit[i] == -1) return false;
        if (visit[i] == 1) return true;
        visit[i] = -1;
        for (auto a : graph[i]) {
            if (!canFinishDFS(graph, visit, a)) return false;
        }
        visit[i] = 1;
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
