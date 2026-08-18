#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> pre(n+1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i-1] + arr[i-1];
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        for (int i = 0; i <= n; i++) {
            dp[i][i] = 0;
        }
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l+len-1 <= n; l++) {
                int r = l+len-1;
                for (int i = l; i < r; i++) {
                    int c = ((pre[r] - pre[i])%100) * ((pre[i] - pre[l-1])%100);
                    if (dp[l][i] == INT_MAX || dp[i+1][r] == INT_MAX) continue;
                    dp[l][r] = min(dp[l][r], (dp[l][i] + dp[i+1][r]) + c);
                }
            }
        }

        cout << dp[1][n] << "\n";
    }
}