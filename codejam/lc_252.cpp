#include "bits/stdc++.h"
using namespace std;
/*
    input la day cac time interval cua cac buoi hop khac nhau.
    Kiem tra xem 1 nguoi co the attend tat ca cac buoi hop hay khong.
    Solution: sap xep cac interval theo tang dan start time.
    neu ton tai start time cua interval i nho hon end time cua interval i-1,=> khong thoa man
*/

bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        return true;
}

int main() {
    vector<vector<int>> meetings;// = {{1,4},{5,10},{12,18}};
    int a,b;

    //freopen("lc_252.txt","r",stdin);
    // de tao EOF trong window stdin, new line: ctr+Z, Enter
    while (scanf("%d %d",&a,&b) != EOF) {
        vector<int> v{a,b};
        meetings.push_back(v);
    }
    if (canAttendMeetings(meetings)) cout<<"ok";
    else cout<<"not ok";

    return 0;
}
