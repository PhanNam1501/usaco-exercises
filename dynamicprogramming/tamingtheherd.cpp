#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }


    vector<vector<int>> cost(N, vector<int>(N + 1, 0));

    for (int l = 0; l < N; l++) {
        for (int r = l + 1; r <= N; r++) {
            int expected = r - l - 1;

            cost[l][r] =
                cost[l][r - 1] +
                (arr[r - 1] != expected);
        }
    }

    const int INF = 1e9;

    vector<vector<int>> dp(
        N + 1,
        vector<int>(N + 1, INF)
    );

    for (int j = 1; j <= N; j++) {
        dp[1][j] = cost[0][j];
    }

    for (int k = 2; k <= N; k++) {
        for (int j = k; j <= N; j++) {

            for (int prev = k - 1; prev < j; prev++) {

                if (dp[k - 1][prev] == INF)
                    continue;

                dp[k][j] = min(
                    dp[k][j],
                    dp[k - 1][prev] + cost[prev][j]
                );
            }
        }
    }

    for (int k = 1; k <= N; k++) {
        cout << dp[k][N] << '\n';
    }
}