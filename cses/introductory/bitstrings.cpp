#include<bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    long long INF = 1000000007;
    vector<long long> dp(n+1, 0);
    dp[0] = 1LL;
    for (int i = 1; i <= n; i++) {
        dp[i] = (2LL * dp[i-1])%INF;
    }

    cout << dp[n];

}