#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> height(N);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }
    
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i-j] + abs(height[i] - height[i-j]));
            }
        }
    }
    cout << dp[N-1] << "\n";
}