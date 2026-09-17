#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> st;
    vector<int> pre(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();
        }

        if (!st.empty()) {
            pre[i] = st.top();
        }
        st.push(i);
    }

    stack<int> st1;
    vector<int> pre1(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st1.empty() && arr[i] < arr[st1.top()]) {
            st1.pop();
        }

        if (!st1.empty()) {
            pre1[i] = st1.top();
        }
        st1.push(i);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = pre[i];
        if (t != -1) {
            res++;
            while(pre1[t] != -1) {
                res++;
                t = pre1[t];
            }
        }
    }

    cout << res << "\n";
}