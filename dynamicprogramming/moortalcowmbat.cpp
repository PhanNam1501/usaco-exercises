#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    string s;
    cin >> s;

    vector<vector<int>> dist(M, vector<int>(M));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> dist[i][j];
        }
    }

    // Floyd-Warshall
    for (int k = 0; k < M; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                dist[i][j] = min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]
                );
            }
        }
    }

    // cost[i][c]:
    // cost to change s[0..i-1] into character c
    vector<vector<long long>> cost(
        N + 1,
        vector<long long>(M, 0)
    );

    for (int i = 1; i <= N; i++) {
        int x = s[i - 1] - 'a';

        for (int c = 0; c < M; c++) {
            cost[i][c] =
                cost[i - 1][c] + dist[x][c];
        }
    }

    const long long INF = 4e18;

    vector<long long> dp(N + 1, INF);
    dp[0] = 0;

    // best[c] =
    // min(dp[j] - cost[j][c])
    // for all j <= i-K
    vector<long long> best(M, INF);

    for (int i = K; i <= N; i++) {

        // Add j = i-K
        int j = i - K;

        if (dp[j] != INF) {
            for (int c = 0; c < M; c++) {
                best[c] = min(
                    best[c],
                    dp[j] - cost[j][c]
                );
            }
        }

        for (int c = 0; c < M; c++) {
            dp[i] = min(
                dp[i],
                cost[i][c] + best[c]
            );
        }
    }

    cout << dp[N] << '\n';

    return 0;
}