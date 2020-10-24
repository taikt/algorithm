#include <bits/stdc++.h>
using namespace std;

// bit
void print_binary(int n){
    vector<int> v;
    int len = 8 * sizeof(int);
    int mask = 1;
    while(len--){
        if(n&mask) v.push_back(1);
        else v.push_back(0);
        mask <<= 1;
    }
    while(!v.empty()){
        cout<<v.back();
        v.pop_back();
    }
    cout<<endl;
}

int update_bits(int n, int m, int i, int j){
    // create a mask to clear bits i though j in n
    int allones = ~0; // all bits 1s
    // 1s before postion j, then 0s. left 11100000
    int left = allones << (j+1);
    int right = ((1 << i) -1);
    int mask = left | right;
    return (n & mask) | (m << i);
}
int main(){
    int n = 1<<10, m = 19;
    int i=2,j=6;
    int ans = update_bits(n, m, i, j);
    cout<<"print n\n";
    //print_binary(n);
    cout<<bitset<32>(n)<<"\n";
    cout<<"print m\n";
    print_binary(m);
    cout<<"insert m into n at positions ["<<i<<","<<j<<"]"<<"\n";
    print_binary(ans);
    return 0;
}
