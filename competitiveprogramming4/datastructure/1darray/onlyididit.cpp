#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n1, n2, n3;

        cin >> n1;
        vector<int> t1(n1);
        for (int i = 0; i < n1; i++) {
            cin >> t1[i];
        }

        cin >> n2;
        vector<int> t2(n2);
        for (int i = 0; i < n2; i++) {
            cin >> t2[i];
        }

        cin >> n3;
        vector<int> t3(n3);
        for (int i = 0; i < n3; i++) {
            cin >> t3[i];
        }

        unordered_map<int, int> mp;

        for (int x : t1)
            mp[x] |= 1;

        for (int x : t2)
            mp[x] |= 2;

        for (int x : t3)
            mp[x] |= 4;

        int c1 = 0, c2 = 0, c3 = 0;

        for (auto [problem, mask] : mp) {
            if (mask == 1)
                c1++;
            else if (mask == 2)
                c2++;
            else if (mask == 4)
                c3++;
        }

        cout << c1 << " " << c2 << " " << c3 << "\n";
    }
}