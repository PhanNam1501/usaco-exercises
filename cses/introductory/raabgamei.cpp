#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b > n) {
            cout << "NO" << "\n";
            continue;
        }

        if ((a > 0 && b == 0) || (a == 0 && b > 0)) {
            cout << "NO\n";
            continue;
        }

        vector<int> p1, p2;
        for (int i = 1; i <= n; i++) {
            p1.push_back(i);
        }

        for (int i = a+1; i <= a+b; i++) {
            p2.push_back(i);
        }
        for (int i = 1; i <= a; i++) {
            p2.push_back(i);
        }

        for (int i = a+b+1; i <= n; i++) {
            p2.push_back(i);
        }
        cout << "YES" << "\n";
        for (int i = 0; i < n; i++) {
            cout << p1[i] << " ";
        }
        cout << "\n";

        for (int i = 0; i < n; i++) {
            cout << p2[i] << " ";
        }

        cout << "\n";
    }
}