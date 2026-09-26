#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;


    vector<vector<vector<long long>>> dp(14, vector<vector<long long>>(14, vector<long long>(14, 0)));
    dp[1][1][1] = 1;
    for (int i = 2; i <= 13; i++) {
        for (int l = 1; l <= 13; l++) {
            for (int r = 1; r <= 13; r++) {
                dp[i][l][r] = dp[i-1][l-1][r] + dp[i-1][l][r-1] + (long long)(i-2) * dp[i-1][l][r];
            }
        }
    }
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        cout << dp[n][l][r] << "\n";
    }
}