#include <iostream>
using namespace std;

int count_one(int x){
    int cnt = 0;
    for(int i=0; i<32; ++i){
        if(x & 1) ++cnt;
        x >>= 1;
    }
    return cnt;
}

int next(int x){
    int max_int = ~(1<<31);
    int num = count_one(x);
    if(num == 0 || x == -1) return -1;
    for(++x; count_one(x) != num && x < max_int; ++x);
    if(count_one(x) == num) return x;
    return -1;
}
int previous(int x){
    int min_int = (1<<31);
    int num = count_one(x);
    if(num == 0 || x == -1) return -1;
    for(--x; count_one(x) != num && x > min_int; --x);
    if(count_one(x) == num) return x;
    return -1;
}

// 1101 1001 1111 00 =>
// 1101 1010 0011 11 (next larger number that same #bits 1)
// algorithm
// 1. flip rightmost non-trailing zero (0->1), position p: c1 ones + c0 zero in [0,p-1]
// 2. clear bits to right of p
// 3. insert c1-1 ones from right
int next1(int n) {
    // compute c0,c1
    int c=n;
    int c0=0, c1=0;
    //c=c&1;
    int t = c&1;
    while (((c&1) == 0)  && (c != 0)) {
        c0++;
        c>>=1;
    }
    while ((c&1==1)) {
        c1++;
        c>>=1;
    }
    // if n=111..1 00..0, no bigger number with same #1
    if (c0+c1 ==31 || c0+c1==0) return -1;
    int p = c0+c1; // position of rightmost non-trailing zero
    n |= (1<<p); // flip rightmost non-trailing zero
    // clear all bits to right of p
    n &= ~((1<<p)-1);
    // insert c1-1 ones to right
    n |= (1<<(c1-1)) -1;

    return n;
}

// 1001 1110 0000 11 =>
// 1001 1101 1100 00
int previous1(int n){
    int temp= n;
    int c0 = 0;
    int cl= 0;
    while (temp&1==1) {
        cl++;
        temp>>= 1;
    }
    if (temp == 0) return -1;
    while (((temp & 1) == 0) && (temp!= 0)) {
        c0++;
        temp>>= 1;
    }

    int p = c0 + cl; // position of rightmost non-trailing one
    n &= ((-0) << (p + 1)); // clears from bit p onwards
    int mask= (1 << (cl + 1)) - 1; // Sequence of (cl+l) ones
    n |= mask<< (c0 - 1);
    return n;
}


