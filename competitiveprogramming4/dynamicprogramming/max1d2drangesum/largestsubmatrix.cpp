#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<string> arr(n);
        arr[0] = s;
        for (int i = 1; i < n; i++) {
            cin >> arr[i];
        }
        vector<vector<int>> A(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = int(arr[i][j]-'0');
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) A[i][j] += A[i][j-1];
            }
        }

        int maxSubRect = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int subRect = 0;
                for (int row = 0; row < n; row++) {
                    int t = 0;
                    if (i > 0) t = A[row][j] - A[row][i-1];
                    else t = A[row][j];
                    if (t < j - i + 1) {
                        subRect = 0;
                        continue;
                    }
                    subRect += t;
                    maxSubRect = max(maxSubRect, subRect);
                }
            }
        }

        cout << maxSubRect << "\n";
        if (T > 0) cout << "\n";
    }
}