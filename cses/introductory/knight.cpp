#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n; 
    cin >> n;

    vector<long long> dp(n+1);
    dp[1] = 0;
    dp[2] = 0;
    for (int i = 3; i <= n; i++) {
        long long corners = 3 * 2;
        long long middles = 0;
        if (i == 3) {
            middles = 2;
        } else if (i == 4) {
            middles = 4 * 3 - 2;
        } else {
            // middles = 4 * 3 + 6;
            middles = 4 * 3 + ((((i*1LL-4) * 2) * 4) - 2);
        }

        dp[i] = dp[i-1] + corners + middles;
    }

    for (long long i = 1; i <= n; i++) {
        cout << ((i*i) * (i*i-1) / 2) - dp[i] << "\n";
    }
}