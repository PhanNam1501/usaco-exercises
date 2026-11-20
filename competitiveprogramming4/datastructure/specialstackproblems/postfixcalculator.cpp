
#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> level;

int calc(vector<string> &A) {
    stack<int> st;

    for (string token : A) {
        if (isdigit(token[0])) {
            st.push(stoi(token));
        } else {
            int x = st.top();
            st.pop();

            int y = st.top();
            st.pop();

            if (token == "+") st.push(y + x);
            else if (token == "-") st.push(y - x);
            else if (token == "*") st.push(y * x);
            else if (token == "/") st.push(y / x);
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

    vector<string> postfix;
    stack<char> st;

    // Infix -> Postfix
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            string num;

            while (i < n && isdigit(s[i])) {
                num += s[i];
                i++;
            }

            postfix.push_back(num);
            i--;
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix.push_back(string(1, st.top()));
                st.pop();
            }

            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                   level[s[i]] <= level[st.top()]) {
                postfix.push_back(string(1, st.top()));
                st.pop();
            }

            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        postfix.push_back(string(1, st.top()));
        st.pop();
    }

    // Evaluate Postfix
    cout << calc(postfix) << '\n';

    return 0;
}
