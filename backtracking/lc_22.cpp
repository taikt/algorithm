#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
        if (left > right) return; //without this, can create invalid case: )(())(
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);
            if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }
};

class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(0, 0, "", res, n);
        return res;
    }
    // left: open bracket (
    // right: right bracket )
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res, int max) {
        if (out.length() == 2*max) {res.push_back(out); return;}
        if (left < max)
            generateParenthesisDFS(left + 1, right, out + '(',res,max);
        if (right < left) // if right < max => create invalid cases: ))()((
            generateParenthesisDFS(left, right+1, out + ')', res,max);
    }
};

#if 0
int main() {
    freopen("lc_22.inp","r",stdin);
    freopen("lc_22.out","w",stdout);
    int n;
    scanf("%d\n",&n);
    Solution su;
    vector<string> out = su.generateParenthesis(n);
    for (auto a:out)
        cout<<a<<"\n";

    return 0;
}
#endif
