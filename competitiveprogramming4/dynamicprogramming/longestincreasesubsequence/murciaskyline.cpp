#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, vector<int> &width) {
    int maxx = 0;
    int N = A.size();
    vector<int> dp(N);
    for (int i = 0; i < N; i++) {
        dp[i] = width[i];
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + width[i]);
            } 
        }
        maxx = max(maxx, dp[i]);
    }

    return maxx;
}

int main() {
    int T;
    cin >> T;
    int cases = 1;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        vector<int> width(N);
        for (int i = 0; i < N; i++) cin >> width[i];

        int increasing = solve(A, width);
        reverse(A.begin(), A.end());
        reverse(width.begin(), width.end());
        int decreasing = solve(A, width);
        if (increasing >= decreasing) {
            cout << "Case " << cases << ". Increasing (" << increasing << "). Decreasing (" << decreasing << ").\n";
        } else {
            cout << "Case " << cases << ". Decreasing (" << decreasing << "). Increasing (" << increasing << ").\n";
        }
        cases++;
    }
}