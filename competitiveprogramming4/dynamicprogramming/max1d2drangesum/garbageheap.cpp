#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    
    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;
        
        long long summ = 0;
        vector<vector<vector<long long>>> arr(A, vector<vector<long long>>(B, vector<long long>(C)));
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> arr[i][j][k];
                    summ += arr[i][j][k];
                }
            }
        }

        vector<vector<vector<long long>>> dp(A+1, vector<vector<long long>>(B+1, vector<long long>(C+1, 0)));
        for (int i = 1; i <= A; i++) {
            for (int j = 1; j <= B; j++) {
                for (int k = 1; k <= C; k++) {
                    dp[i][j][k] = arr[i-1][j-1][k-1] + dp[i-1][j][k] + dp[i][j-1][k] + dp[i][j][k-1] 
                                - dp[i-1][j-1][k] - dp[i-1][j][k-1] - dp[i][j-1][k-1] + dp[i-1][j-1][k-1];
                }
            }
        }

        long long maxx = -2e18; 
        for (int i = 1; i <= A; i++) {
            for (int j = 1; j <= B; j++) {
                for (int k = 1; k <= C; k++) {
                    for (int l = i; l <= A; l++) {
                        for (int r = j; r <= B; r++) {
                            for (int h = k; h <= C; h++) {
                                long long t = dp[l][r][h] - dp[i-1][r][h] - dp[l][j-1][h] + dp[i-1][j-1][h] 
                                            - dp[l][r][k-1] + dp[i-1][r][k-1] + dp[l][j-1][k-1] - dp[i-1][j-1][k-1];  
                                maxx = max(maxx, t);
                            }
                        }
                    }
                }
            }
        }
        cout << maxx << "\n";
        if (T > 0) cout << "\n";
    }
    return 0;
}