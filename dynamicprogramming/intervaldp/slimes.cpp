#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<ll> pre(N+1, 0);
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i-1] + arr[i-1];
    }
    ll INF = LONG_LONG_MAX; // should use long long max, or calculate exactly max of sum
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, INF));
    for (int i = 0; i <= N; i++) {
        dp[i][i] = 0;
    }
    for (int len = 2; len <= N; len++) {
        for (int l = 1; l+len-1 <= N; l++) {
            int r = l+len-1;
            for (int i = l; i < r; i++) {
                if (dp[l][i] == INF || dp[i+1][r] == INF) continue;
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i+1][r] + pre[r] - pre[l-1]); 
            }
        }
    }

    cout << dp[1][N] << "\n";
}