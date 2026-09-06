#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<ll> pre(n+1, 0);
        unordered_map<ll, ll> cnt;
        cnt[0] = 1;
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] = (pre[i-1]-1) + (ll)(s[i-1]-'0');

            res += cnt[pre[i]];
            cnt[pre[i]]++;
        }

        cout << res << "\n";
    }
}

// test 