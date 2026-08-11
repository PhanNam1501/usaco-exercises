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
            if (i-c >= 0 && dp[i] > dp[i-c]+1) {
                dp[i] = dp[i-c]+1;
            }
        }
    }

    cout << dp[n] << "\n";
}