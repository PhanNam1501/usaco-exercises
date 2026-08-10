#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> coins(k);
    for (int i = 0; i < k; i++) {
        cin >> coins[i];
    }
    vector<int> dp(n+1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto c : coins) {
            int t1 = i >= c ? dp[i-c] : 0;
            dp[i] = min(dp[i], t1 + 1);
        }
    }

    cout << dp[n] << "\n";
}