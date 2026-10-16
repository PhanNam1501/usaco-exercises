#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<vector<int>> dp(n+1, vector<int>(2));
        dp[0][0] = INT_MIN;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = max(dp[i-1][1] + arr[i-1], arr[i-1]);
        }
        int res = max(dp[n][0], dp[n][1]);
        if (res > 0) {
            cout << "The maximum winning streak is " << res << ".\n"; 
        } else {
            cout << "Losing streak.\n";
        }
    }
}