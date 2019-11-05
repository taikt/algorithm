/*
* 
*
*/

#include <vector>
#include <stack>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int minMeetingRooms(vector<vector<int>>& intervals) {
        	map<int,int> m;
        	for (auto a: intervals) {
        		++m[a[0]];
        		--m[a[1]];
        		printf("a[0]=%d, a[1]=%d => %d,%d\n",a[0],a[1],m[a[0]],m[a[1]]);
        	}
        	int rooms = 0, res=0;
        	for (auto it:m) {
        		//res = max(res, rooms += it.second);
        		printf("%d(value=%d)\n",it.first,it.second);
        		//printf("[%d=> %d]\n", it.second, rooms);
        	}
        	return res;

        }
};

int main() {
	Solution anw;
	vector<vector<int>> intervals= {
		{7,10},
		{2,4}	
	};
	printf("%d\n",anw.minMeetingRooms(intervals));


    return 0;
}
