#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) arr[i][j] += arr[i][j-1];
        }
    }
    int maxSubRect = INT_MIN;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int subRect = 0;
            for (int row = 0; row < n; row++) {
                if (l > 0) subRect += arr[row][r] - arr[row][l-1];
                else subRect += arr[row][r];

                if (subRect < 0) subRect = 0;
                maxSubRect = max(maxSubRect, subRect);
            }
        }
    }

    cout << maxSubRect << "\n";
}