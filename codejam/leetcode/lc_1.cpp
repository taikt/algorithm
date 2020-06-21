/*
    two sum: cho mang cac so nguyen, va mot so cho truoc
    tim index 2 thanh phan trong mang ma tong bang so cho truoc
    vd: [2,7,8,12,1], so cho truoc: 9
    ==> index [2,4] vi 8+1=9

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v{2,8,8,12,3};
    int n=9;

/*
method 1: hash O(1)
bang map luu cap (index, value): index - gia tri phan tu, value - index vi tri phan tu
chen cac cap vao tu mang vao bang hash.
loop for moi phan tu, tai moi phan tu, tim kiem ton tai phan bu cua no trong bang hash (phan bu: given number - gia tri phan tu hien tai)
tim kiem bang hash cho toc do nhanh O(1)
Total complexity: O(n)
*/

#if 1
    unordered_map<int,int> m;
    for (int i=0; i<v.size(); i++) {
        m[v[i]] = i; // moi phan tu cua map (key,value): key=thanh phan mang, value=gia tri index
        //cout<<v[i]<<","<<i<<'\n';
    }
    bool find = false;
    for (int i=0; i<v.size(); i++) {
        //if (m.find(n-v[i]) != m.end() && (i != m[n-v[i]]))
        if (m.count(n-v[i]) && (i != m[n-v[i]]))
        {
            cout<<i<<","<<m[n-v[i]]<<"\n";
            find = true;
            //return {i,m[n-v[i]]};
            break;
        }
        // extend performance: neu khong thay phan bu trong bang hash moi add gia tri phan tu hien tai vao bang hash
        // khong can add moi phan tu vao hash tu dau
    }
    if (!find) cout<<"not found\n";
    //return {};
#endif // 0

/*
variant problem: chi can check ton tai cap so co tong bang so cho truoc,
khong yeu cau tim vi tri index.
method: two pointer
sap xep lai mang theo thu tu tang dan, sau do dung two pointer
time complexity: O(nlogn)
*/
#if 0
    sort(v.begin(), v.end(),[](int a, int b) {return a<b;}); //O(nlogn)

    int start = 0, end = v.size() -1;
    while (start < end) { // O(n)
        if (v[start] + v[end] < n) start++;
        else if (v[start] + v[end] > n) end--;
        else {
            cout<<"found!\n";
            break;
        }
    }
    if (start >= end) cout<<"not found\n";
#endif // 0

/*
method 3 (not recommend): dung hash truc tiep, khong dung thu vien
*/
#if 0
    #define SIZE 50000
    int hash(int key) {
        int r = key % SIZE;
        return r < 0 ? r + SIZE : r;
    }

    void insert(int *keys, int *values, int key, int value) {
        int index = hash(key);
        while (values[index]) {
            index = (index + 1) % SIZE;
        }

        printf("[insert] index=%d, key=%d, value=%d\n",index, key, value);

        keys[index] = key;
        values[index] = value;
    }

    int search(int *keys, int *values, int key) {
        int index = hash(key);
        while (values[index]) {
            if (keys[index] == key) {
                return values[index];
            }
            index = (index + 1) % SIZE;
        }
        return 0;
    }

    int* twoSum(int* nums, int numsSize, int target) {
        int keys[SIZE];
        int values[SIZE] = {0};
        int i;
        for (i = 0; i < numsSize; i++) {
            int complements = target - nums[i];
            int value = search(keys, values, complements);
            if (value) {
                int *indices = (int *) malloc(sizeof(int) * 2);
                indices[0] = value - 1;
                indices[1] = i;
                return indices;
            }
            insert(keys, values, nums[i], i + 1);
        }
        return NULL;
    }
#endif // 0
    return 0;
}
