#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int> level;

int calc(vector<char> &A) {
    stack<int> st;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        if (int(A[i]-'0') >= 0 && int(A[i]-'0') <= 9) {
            st.push(int(A[i]-'0'));
        } else if (A[i] == '+') {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(x+y);
        } else if (A[i] == '-') {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(y-x);
        } else if (A[i] == '*') {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(x*y);
        } else {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(y/x);
        }
    }

    return st.top();
}

int main() {
    level['+'] = 1;
    level['-'] = 1;
    level['*'] = 2;
    level['/'] = 2;
    string s;
    cin >> s;
    int n = s.size();
    vector<char> postfix;
    stack<char> st;
    for (int i = 0; i < n; i++) {
        if (int(s[i]-'0') <= 9 && int(s[i]-'0') >= 0) {
            postfix.push_back(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        } else {
            while (s[i] != '(' && !st.empty() && level[s[i]] <= level[st.top()]) {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }

    // for (int i = 0; i < postfix.size(); i++) {
    //     cout << postfix[i];
    // }

    cout << calc(postfix);
}

