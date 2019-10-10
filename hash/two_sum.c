/**
 *
 * https://leetcode.com/problems/two-sum/
 *
 * C solution in O(n) time, using open addressing hash table.
 */
#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int arr[] = {2,12,7,15};
    int* index = twoSum(arr,4,9);
    if (index) printf("indexs=%d,%d\n",*index, *(index+1));
        else printf("not found\n"); 

    return 0;
}
