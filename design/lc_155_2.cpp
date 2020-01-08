// https://leetcode.com/problems/min-stack/
// dung 2 stack, 1 stack goc, 1 min stack

#include <bits/stdc++.h>
using namespace std;

class MinStack {
    public:
    /** initialize your data structure here. */
    MinStack() {
    }
    void push(int x) {
        st.push(x);
        if (minSt.empty() || (x <= minSt.top())) minSt.push(x);
    }

    void pop() {
        if (st.top()== minSt.top()) minSt.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }

    private:
        stack<int> st, minSt;
};

int main() {
    freopen("lc_155.inp","r",stdin);
    freopen("lc_155.out","w",stdout);


    MinStack minStack; // = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<minStack.getMin()<<endl;   //--> Returns -3.
    minStack.pop();
    cout<<minStack.top()<<endl;      //--> Returns 0.
    cout<<minStack.getMin()<<endl;   //--> Returns -2.

    return 0;
}

