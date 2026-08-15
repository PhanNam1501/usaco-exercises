#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, H;
    cin >> W >> H;

    int N;
    cin >> N;

    vector<vector<bool>> good(W + 1, vector<bool>(H + 1, false));

    for (int i = 0; i < N; i++) {
        int w, h;
        cin >> w >> h;

        if (w <= W && h <= H) {
            good[w][h] = true;
        }
    }

    vector<vector<int>> dp(W + 1, vector<int>(H + 1, 0));

    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {

            if (good[i][j]) {
                dp[i][j] = i * j;
                continue;
            }

            for (int x = 1; x < i; x++) {
                dp[i][j] = max(
                    dp[i][j],
                    dp[x][j] + dp[i - x][j]
                );
            }

            for (int x = 1; x < j; x++) {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i][x] + dp[i][j - x]
                );
            }
        }
    }

    cout << W * H - dp[W][H] << '\n';
}