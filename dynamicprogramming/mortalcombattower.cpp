#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

int countOnes(int x, int y) {
    int res = 0;
    for (int i = x; i < y; i++)
        if (arr[i] == 1) res++;
    return res;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        arr.resize(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        vector<vector<int>> dp(N+1, vector<int>(2, INT_MAX));
        dp[0][0] = INT_MAX; 
        dp[0][1] = 0;       

        for (int i = 1; i <= N; i++) {
            if (dp[i-1][1] != INT_MAX) {
                dp[i][0] = min(dp[i][0], dp[i-1][1] + countOnes(i-1, i));
            }
            if (i >= 2 && dp[i-2][1] != INT_MAX) {
                dp[i][0] = min(dp[i][0], dp[i-2][1] + countOnes(i-2, i));
            }

            dp[i][1] = min(dp[i][1], dp[i-1][0]);
            if (i >= 2 ) {
                dp[i][1] = min(dp[i][1], dp[i-2][0]);
            }
        }

        cout << min(dp[N][0], dp[N][1]) << "\n";
        arr.clear();
    }
}