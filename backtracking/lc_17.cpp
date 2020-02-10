// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return {};
		vector<string> res;
		vector<string> dict{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		letterCombinationsDFS(digits,dict,0,"",res);
		return res;
	}

	// input: string& digits or string digits is both ok
	// string& digits: can modify original string by using reference
	void letterCombinationsDFS(string digits, vector<string>& dict, int lev, string out, vector<string>& res) {
		if (lev == digits.size()) { res.push_back(out); return;}
		string str = dict[digits[lev] - '0'];
		FOR(i,0,str.size()) {
			letterCombinationsDFS(digits, dict, lev+1, out+str[i],res);
		}
	}
};


int main() {
    freopen("lc_17.inp","r",stdin);
    freopen("lc_17.out","w",stdout);
    string s;
    getline(cin,s);
    Solution su;
    vector<string> ret = su.letterCombinations(s);
    for (auto a: ret) {
    	cout<<a<<"\n";
    }

    return 0;
}
