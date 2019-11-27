#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define SPLIT4(x, a, b, c) for (a = 0; a <= x; a++) for (b = 0; a + b <= x; b++) for (c = 0; a + b + c <= x; c++)
#define LL long long
#define expand(mask) mask[0]][mask[1]][mask[2]

#define maxN 50005
#define MOD 1000000007
#define increaseMod(a, b) a = ((LL)a + (LL)b) % MOD

inline LL fpow(LL n, LL k, int p = MOD) {LL r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

string P, Q;

int targetMasks[5][4] = {
    {10, 0, 0, 0},
    {9, 0, 1, 0},
    {9, 1, 0, 0},
    {9, 0, 0, 1},
    {8, 1, 1, 0}
};
int dp[maxN][11][11][11];
int countMask[11][11][11];
int invCountMask[11][11][11];
int c[11][11];
map<pair<pair<int, int>, int>, int> maskTransitions[11][11][11];

//inline void increaseMod(int &a, LL x) {
//    a = (x + a) % MOD;
//}

void preProcessDP() {
    int s0, s1, s2;
    dp[0][10][0][0] = 1;
    FOR(i, 0, Q.size() - 1) {
        SPLIT4(10, s0, s1, s2) if (dp[i][s0][s1][s2]) {
            int s3 = 10 - s0 - s1 - s2;
            LL r = dp[i][s0][s1][s2];
            if (s0 != 0 && s1 != 10) {
                // i-th digit in s0, s0 dec, s1 inc
                increaseMod(dp[i + 1][s0 - 1][s1 + 1][s2], r * s0);
            }
            if (s1 != 0 && s2 != 10) {
                // i-th digit in s1, s1 dec, s2 inc
                increaseMod(dp[i + 1][s0][s1 - 1][s2 + 1], r * s1);
            }
            if (s2 != 0 && s3 != 10) {
                // i-th digit in s2, s2 dec, s3 inc
                increaseMod(dp[i + 1][s0][s1][s2 - 1], r * s2);
            }
            if (s3 != 0 && s0 != 10) {
                // i-th digit in s3, s3 dec, s0 inc
                increaseMod(dp[i + 1][s0 + 1][s1][s2], r * s3);
            }
        }
    }
    FOR(i, 0, Q.size()) {
        SPLIT4(10, s0, s1, s2) if (dp[i][s0][s1][s2]) {
            LL t = (LL)dp[i][s0][s1][s2] * invCountMask[s0][s1][s2];
            dp[i][s0][s1][s2] = t % MOD;
        }
    }
}

void preProcessC() {
    c[0][0] = 1;
    FOR(i, 1, 10) {
        c[0][i] = c[i][i] = 1;
        FOR(j, 1, i - 1) c[j][i] = c[j-1][i-1] + c[j][i-1];
    }
}

int countSplit(int P, int x, int y, int z) {
    LL res = 1;
    res = (res * c[x][P]) % MOD;
    res = (res * c[y][P-x]) % MOD;
    res = (res * c[z][P-x-y]) % MOD;
    return res;
}

bool isTarget(const int *mask) {
    FOR(target, 0, 4) {
        bool matchTarget = true;
        FOR(x, 0, 3) matchTarget = matchTarget & (mask[x] == targetMasks[target][x]);
        if (matchTarget) return true;
    }
    return false;
}

void preProcessMaskTransition() {
    int os[4];
    int ns[4];
    int fs[4];
    int cs[4][4];
    SPLIT4(10, os[0], os[1], os[2]) {
        os[3] = 10 - os[0] - os[1] - os[2];
        SPLIT4(os[0], cs[0][0], cs[0][1], cs[0][2])
        SPLIT4(os[1], cs[1][0], cs[1][1], cs[1][2])
        SPLIT4(os[2], cs[2][0], cs[2][1], cs[2][2])
        SPLIT4(os[3], cs[3][0], cs[3][1], cs[3][2]) {
            FOR(j, 0, 3) cs[j][3] = os[j] - cs[j][0] - cs[j][1] - cs[j][2];
            
            memset(ns, 0, sizeof(ns));
            FOR(j, 0, 3) {
                FOR(i, 0, 3) ns[j] += cs[i][j];
            }
            memset(fs, 0, sizeof(fs));
            FOR(x, 0, 3) FOR(y, 0, 3) {
                fs[(x + y) % 4] += cs[x][y]; //change from x -> y
            }
            if (!isTarget(fs)) continue;

            LL res = 1;
            FOR(i, 0, 3) res = res * countSplit(os[i], cs[i][0], cs[i][1], cs[i][2]) % MOD;
            
            pair<pair<int, int>, int> key = make_pair(make_pair(ns[0], ns[1]), ns[2]);
            int tmp;
            if (maskTransitions[expand(os)].count(key))  {
                tmp = maskTransitions[expand(os)][key];
            } else {
                tmp = 0;
            }
            maskTransitions[expand(os)][key] = (tmp + res) % MOD;
        }
    }
}

void preProcessCountMask() {
    int s[4];
    SPLIT4(10, s[0], s[1], s[2]) {
        countMask[expand(s)] = countSplit(10, s[0], s[1], s[2]);
        invCountMask[expand(s)] = inv(countMask[expand(s)]);
    }
}

void preProcess() {
    preProcessC();
    preProcessCountMask();
    preProcessDP();
    preProcessMaskTransition();
}

int countRemaining(const int* currMask, int remainLength) {
    int res = 0;
    int newMask[4];
    for (auto trans: maskTransitions[expand(currMask)]) {
        newMask[0] = trans.first.first.first;
        newMask[1] = trans.first.first.second;
        newMask[2] = trans.first.second;
        long long tmp = (LL)(trans.second) * dp[remainLength][expand(newMask)];
        res = (res + (tmp % MOD)) % MOD;
    }
    return res;
}

int process(string &N) {
    //count super palindrome in range [1, N)
    int res = 0;

    //smaller length
    FOR(len, 1, N.size() - 1) {
        FOR(firstDigit, 1, 9) { // make sure first digit is not zero
            int currMask[4] = {9, 1, 0, 0};
            res = (res + countRemaining(currMask, len - 1)) % MOD;
        }
    }
    
    //same length
    int cntDigit[10];
    memset(cntDigit, 0, sizeof(cntDigit));
    FOR(firstDiff, 0, N.size() - 1) {
        int st = (firstDiff == 0 ? 1 : 0);
        FOR(diff, st, N[firstDiff] - '0' - 1) {
            cntDigit[diff]++;
            int currMask[4];
            memset(currMask, 0, sizeof(currMask));
            FOR(i, 0, 9) currMask[cntDigit[i] % 4]++;
            res += countRemaining(currMask, N.size() - firstDiff - 1);
            res %= MOD;
            cntDigit[diff]--;
        }
        cntDigit[N[firstDiff] - '0']++;
    }
    return res;
}

void inc(string& A) {
    int carry = 0;
    FORD(i, A.size() - 1, 0) {
        int t = (i == A.size() - 1 ? 1 : 0) + A[i] - '0' + carry;
        carry = t / 10;
        A[i] = '0' + t % 10;
    }
    if (carry) {
        A = "1" + A;
    }
}

int main() {
    freopen("ASPAL.INP", "r", stdin);
    freopen("ASPAL.OUT", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> P;
    cin >> Q;

//    P = ""; FOR(i, 1, 50000) P = P + "1";
//    Q = ""; FOR(i, 1, 50000) Q = Q + "9";

    inc(Q);
    preProcess();
    cout << (process(Q) - process(P) + MOD) % MOD << endl;
    return 0;
}
