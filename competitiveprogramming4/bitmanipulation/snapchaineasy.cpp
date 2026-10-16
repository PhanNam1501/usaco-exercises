#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; 
    
    for (int c = 1; c <= t; c++) {
        int n, k;
        cin >> n >> k; 
        
        vector<vector<int>> dp(k+1, vector<int>(n+1));
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                int t = 1;
                for (int x = 1; x < j; x++) {
                    t &= dp[i-1][x];
                }
                dp[i][j] = dp[i-1][j] ^ t;    
            }
        }
        int unlight = false;
        for (int i = 1; i <= n; i++) {
            if (dp[k][i] == 0) {
                unlight = true;
                break;
            }
        }

        if (unlight) {
            cout << "CASE #" << c << ": OFF\n";
        } else {
            cout << "CASE #" << c << ": ON\n";
        }
    }
    return 0;
}