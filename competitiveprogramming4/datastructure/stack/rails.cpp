#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    bool first = false;
    while (true) {
        if (first) cout << "\n";
        else first = true;
        cin >> n;
        if (n == 0) break;
        while (true) {
            vector<int> sample(n);
            cin >> sample[0];
            if (sample[0] == 0) {
                break;
            }
            for (int i = 1; i < n; i++) {
                cin >> sample[i];
            }
            int p = 0;
            stack<int> st;
            for (int i = 1; i <= n; i++) {
                if (sample[p] != i) {
                    st.push(i);
                } else {
                    p++;
                }

                while (!st.empty() && st.top() == sample[p]) {
                    p++;
                    st.pop();
                }
            }

            if (p == n) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }
    }
}