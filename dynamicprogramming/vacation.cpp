#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(N+1, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + arr[i-1][j]);
                }
            }
        }
    }

    cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << "\n";
}