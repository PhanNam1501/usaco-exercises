#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> a(k);
    vector<int> b(n);

    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());
    vector<int> pre(k);
    pre[0] = a[0];
    for (int i = 1; i < k; i++) {
        pre[i] = pre[i-1] + a[i];
    }
    sort(pre.begin(), pre.end());

    if (n == 1) {
        int r = 1;
        for (int i = 1; i < k; i++) {
            if (pre[i] != pre[i-1]) r++;
        }
        cout << r << "\n";
        return 0;
    }

    int res = 0;
    for (int i = 0; i < k; i++) {
        int x = b[0] - pre[i];
        int p = 1;
        map<int, bool> mp;
        mp[i] = true;
        while(p < n) {
            bool check = false;
            for (int j = 0; j < k; j++) {
                if (mp[j]) continue;
                if (b[p] - pre[j] == x) {
                    check = true;
                    p++;
                    mp[j] = true;
                    if (p == n) res++;
                }
            }
            if (!check) {
                break;
            }
        }
    }

    cout << res << "\n";
}