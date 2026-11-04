#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n*2);
    for (int i = 0; i < n*2; i++) cin >> arr[i];
    stack<int> st;
    int cnt = 0;
    for (int i = 0; i < n*2; i++) {
        if (!st.empty() && arr[i] == st.top()) {
            st.pop();
        } else {
            st.push(arr[i]);
        }
        cnt++;
    }

    if (!st.empty()) {
        cout << "impossible\n";
    } else {
        cout << cnt << "\n";
    }
}