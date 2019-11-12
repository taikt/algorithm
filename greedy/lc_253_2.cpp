/*
*  https://github.com/grandyang/leetcode/issues/253
*	https://en.cppreference.com/w/cpp/container/priority_queue
* 	http://www.learn4master.com/interview-questions/leetcode/leetcode-meeting-rooms-ii-java

*   Solution: use greedy method
*	sort intervals using start time (ascending order). Try to merge the next one
*	that has smallest start time ts from remaining intervals with
*	previous interval that has smallest end time te.
*	ts < te: cannot merge with all previose intervals => start new room
*	ts >= te: can merge with room with end time te
*
*	use a min-heap (priority queue) to store end times: top node (smallest value) has smallest end time te
*/

#include <vector>
#include <queue> // for priority_queue
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

//testing print a priority queue
template<typename T> void print_queue(T& q) {
	while(!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << "\n---------------\n";
	
}

class Solution {
    public:
	    int minMeetingRooms(vector<vector<int>>& intervals) {
	    	// sort intervals using start time (ascending order)
	    	// with intervals={{7,10},{2,4}}
	    	// i.e a = {7,10}, b={2,4}
	    	// after sorting, intervals={{2,4},{7,10}}
	    	sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){ return a[0] < b[0];});

	    	// use a min priority queue (top node is minimum)
	    	priority_queue<int,vector<int>, greater<int>> q;
	    	// if declare a priority queue like below
	    	// priority_queue<int> q
	    	// then that is a maximum priority queue by default (top node is maximum)
	    	for (auto interval: intervals) {
	    		if (!q.empty() && q.top() <= interval[0]) q.pop();
	    		q.push(interval[1]);
	    	}
	    	priority_queue<int,vector<int>, greater<int>> t=q;
	    	print_queue(t);

	    	return q.size();
	    }
};


int main() {
	Solution anw;
	vector<vector<int>> intervals= {
		{7,10},
		{2,4}	
	};
	printf("num of rooms: %d\n",anw.minMeetingRooms(intervals));

	//test_map();

    return 0;
}
