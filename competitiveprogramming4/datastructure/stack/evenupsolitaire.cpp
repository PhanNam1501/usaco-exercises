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
    int prev = 0;
    for (int i = 0; i < n; i++) {
        st.push(arr[i]);
        if (st.size() >= 2) {
            if ((st.top() + prev) % 2 == 0) {
                st.pop();
                st.pop();
                if (!st.empty()) prev = st.top();
                continue;
            }
        }
        prev = arr[i];
    }

    cout << st.size() << "\n";
}