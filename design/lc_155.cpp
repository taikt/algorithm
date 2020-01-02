#include <bits/stdc++.h>
using namespace std;

class MinStack {
    public:
    /** initialize your data structure here. */
    MinStack() {
        min_value = 1000;
    }

    void push(int x) {
        st.push(x);
        if (x < min_value) {
            old_value = min_value;
            min_value = x;
        }
    }

    void pop() {
        if (st.top()==min_value) min_value = old_value;
        st.pop();

    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_value;
    }

    private:
        stack<int> st;
        int min_value;
        int old_value;
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

