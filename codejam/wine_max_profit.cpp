#include <bits/stdc++.h>
using namespace std;

// input: 1 4 2 3
// out: max_profit = 1*1 + 3*2 + 2*3 + 4*4 = 29
int N;
int cached_profit[100][100];
//vector<vector<int>> cached_profit(100,vector<int>);
vector<int> vec;

int max_profit(int be,int end) {
    if (be>end) return 0;
    int year = N - (end-be+1) +1;
    if  (cached_profit[be][end] != -1) return cached_profit[be][end];
    return (cached_profit[be][end] = max(max_profit(be+1,end) + year*vec[be], max_profit(be,end-1) + year*vec[end]));
}

int main() {
    string st;
    getline(cin,st);
    stringstream str(st);
    int t;
    while (str>>t)
        vec.push_back(t);
    N = vec.size();
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cached_profit[i][j] = -1;
        }
    }
    for (auto a:vec)
        cout<<a<<" ";
    //cout<<"\n"<<N;
    cout<<"max profit: "<<max_profit(0,N-1);

    return 0;
}
