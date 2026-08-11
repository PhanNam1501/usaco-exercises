#include <bits/stdc++.h>
using namespace std;

bool checkwin(char x, char y) {
    if (x == 'H' && y == 'S') return true;
    if (x == 'S' && y == 'P') return true;
    if (x == 'P' && y == 'H') return true;
    return false;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<char> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<char> str = {'H', 'P', 'S'};

    // dp[i][k][g]
    // i = đã chơi i ván
    // k = đã đổi gesture k lần
    // g = gesture hiện tại
    vector<vector<vector<int>>> dp(
        N + 1,
        vector<vector<int>>(K + 1, vector<int>(3, -1))
    );

    // Ván 0: có thể bắt đầu bằng bất kỳ gesture nào
    for (int g = 0; g < 3; g++) {
        dp[0][0][g] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int k = 0; k <= K; k++) {
            for (int g = 0; g < 3; g++) {

                int win = checkwin(str[g], arr[i - 1]);

                // No change
                if (dp[i-1][k][g] != -1) {
                    dp[i][k][g] = max(dp[i][k][g], dp[i-1][k][g] + win);
                }

                if (k > 0) {
                    for (int prev = 0; prev < 3; prev++) {
                        if (prev == g) continue;
                        if (dp[i-1][k][g] != -1) {
                            dp[i][k][g] = max(dp[i][k][g], dp[i-1][k-1][prev] + win);
                        }
                    }
                }
                
            }
        }
    }

    int res = 0;

    for (int k = 0; k <= K; k++) {
        for (int g = 0; g < 3; g++) {
            res = max(res, dp[N][k][g]);
        }
    }

    cout << res << '\n';
}