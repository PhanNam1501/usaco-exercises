#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> getMax(N+1, vector<int>(N+1));
    for (int i = 0; i < N; i++) {
        for (int j = i; j >= 0; j--) {
            if (i == j) {
                getMax[j+1][i+1] = arr[i];
            } else {
                getMax[j+1][i+1] = arr[j] > getMax[j+2][i+1] ? arr[j] : getMax[j+2][i+1]; 
            }
        }
    }

    vector<int> dp(N+1, -1);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < K; j++) {
            if (i >= j) {
                dp[i] = max(dp[i], dp[i - j - 1] + getMax[i-j][i] * (j+1));
            }
        }
    }

    cout << dp[N] << "\n";
}