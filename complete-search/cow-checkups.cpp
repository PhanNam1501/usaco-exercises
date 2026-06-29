// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read from input file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Parse input
    int N;
    cin >> N;
    
    vector<int> res(N+1, 0);
    vector<int> a(N+1), b(N+1);
    for (int i=1;i<=N;i++) cin>>a[i];
    for (int i=1;i<=N;i++) cin>>b[i];

    vector<int> pre(N+2, 0);
    vector<int> suf(N+2, 0);
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i-1] + (a[i] == b[i]);
    }

    for (int i = N; i >= 1; i--) {
        suf[i] = suf[i+1] + (a[i] == b[i]);
    }

    vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));
    for (int i = 1; i <= N; i++) {
        dp[i][i] = (a[i] == b[i]);
    }

    for (int l = 1; l < N; l++) {
        int r = l + 1;
        dp[l][r] = (a[r] == b[l]) + (a[l] == b[r]);
    }

    for (int len = 3; len <= N; len++) {
        for (int l = 1; l + len - 1 <= N; l++) {
            int r = l + len - 1;
            dp[l][r] = dp[l+1][r-1];
            dp[l][r] += (a[l] == b[r]) + (a[r] == b[l]);
        }
    }

    for (int l = 1; l <= N; l++) {
        for (int r = l; r <= N; r++) {
            int cnt = pre[l-1] + dp[l][r] + suf[r+1];
            res[cnt]++;
        }
    }



    // Solution here
    for (int i = 0; i <= N; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}

