#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(N);
    for (int cnt = 0; cnt < 3; cnt++) {
        for (int i = 0; i < N; i++) {
            if (cnt == 0) {
                cin >> a[i];
            } else if (cnt == 1) {
                cin >> b[i];
            } else {
                cin >> c[i];
            }
        }
    }

    map<int, vector<int>> mp;
    for (int i = 0; i < N; i++) {
        mp[a[i]].push_back(i);
    }


    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int t = b[c[i]-1];
        ans += mp[t].size();
    }

    cout << ans << "\n";
}