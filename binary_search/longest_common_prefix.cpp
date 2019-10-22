/*
 * https://www.geeksforgeeks.org/longest-common-prefix-using-binary-search/
 *
 */

#include <bits/stdc++.h>
using namespace std;

int findMinLength(string arr[], int n) 
{
    int min = INT_MAX;

    for (int i=0; i<=n-1; i++)
        if (arr[i].length() < min)
            min = arr[i].length();

    return min;
}

bool allContainPrefix(string arr[], int n, string str, int start, int end) {
    for (int i=0; i<=n-1; i++) 
        for (int j=start; j<=end; j++)
            if (arr[i][j] != str[j])
                return false;

    return true;
}


string commonPrefix(string arr[], int n) {
    int index = findMinLength(arr,n);

    string prefix;

    int l=0, h=index;

    while (l <= h) {
        int m = (l+h)/2;
        if (allContainPrefix(arr,n,arr[0],l,m)) {
            prefix = prefix + arr[0].substr(l,m-l+1);

            l = m+1;
        }
        else h = m-1;
    }

    return prefix;
}

int main() {
    string arr[] = {"geeksforgeeks", "geek", "geezer"};
    int n = sizeof(arr) / sizeof (arr[0]);

    string ans = commonPrefix(arr,n);

    if (ans.length())
        printf("longest common prefix is %s\n", ans.c_str());
    else 
        printf("no common prefix\n");

    return 0;
}
