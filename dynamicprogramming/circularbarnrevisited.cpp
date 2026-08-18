#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, K;
vector<ll> r;

ll segCost(int start, int length) {
    ll res = 0;
    for (int i = 0; i < length; i++) {
        res += ll(i) * r[(start+i)%n];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> K;
    r.resize(n);
    for (int i = 0; i < n; i++) cin >> r[i];

    ll ans = LLONG_MAX;
    const ll INF = 1e18;


    for (int s = 0; s < n; s++) {
        vector<vector<ll>> dp(K+1, vector<ll>(n+1, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= K; i++) {
            for (int j = i; j <= n; j++) {
                for (int prev = i-1; prev < j; prev++) {
                    if (dp[i-1][prev] == INF) continue;
                    dp[i][j] = min(dp[i][j], dp[i-1][prev] + segCost((s+prev)%n, j-prev));
                } 
            }
        }
        ans = min(ans, dp[K][n]);
    }
    

    cout << ans << "\n";
    return 0;
}