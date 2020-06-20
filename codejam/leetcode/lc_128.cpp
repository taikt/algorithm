/*
cho day so chua duoc sap xep, tim chieu dai day tang lien tuc lon nhat
vd: [2,5,8,9,14,7] => day lien tuc tang dai nhat [7,8,9] => chieu dai max =3
*/
#include <bits/stdc++.h>
using namespace std;

// g++ -g -fsanitize=address lc_128.cpp (only linux work for sanitize address: check overflow)
int main() {
    vector<int> v{0,3,6,4};
    int max_length=0;

    // method 1: su dung hash
    /*
    unordered_set: hash giup tim kiem phan tu nhanh: O(1).
    - add tat ca phan tu vao tap hash
    - duyet day phan tu goc: tai moi phan tu, tim chieu dai day tang dai nhat tu phan tu dang xet(khong co phan tu be hon truoc do)
    - vi khong phai moi phan tu deu thoa man co day goc con tang tai do => (for loop ngoai + while loop trong (khong duyet het moi phan tu)) => O(n)
    */
    #if 0
    unordered_set<int> set(v.begin(),v.end());
    for (auto x:v) {
        if (!set.count(x-1)) {
            //check day con tang xuat phat tu x
            int temp = x, temp_max =0;
            while (set.count(temp)) { // check ton tai phan tu temp
                temp++;
                temp_max++;
            }
            max_length = max(max_length, temp_max);
        }
    }
    #endif // 0

    /*
    method 2: dung sort
    chi can duyet 1 lan: loop for.
    cnt tang deu neu cac phan tu van tang deu, cnt reset(0) neu cac phan tu khong con tang deu
    max length la max cnt
    Time complexity: O(nlogn)
    */
    if (v.size() == 0) return 0;
    sort(v.begin(),v.end(),[](int a, int b){return a<b;}); // O(nlogn)
    int cnt=1;
    for (int i=0; i<v.size();i++) {//not use i+1 to avoid overflow
        if (v[i+1] == v[i]+1) {
            cnt++;
        } else if (v[i+1] == v[i]) {
            //not increase cnt
        } else { //v[i+1] > v[i]+1 => reset cnt
            max_length = max(max_length,cnt); // update max length before reset cnt
            cnt=1;
        }
    }

    cout<<"max length:"<<max_length;

    return 0;
}
