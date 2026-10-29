#include<bits/stdc++.h>
using namespace std;

int main() {
    int p;
    cin >> p;
    while (p--) {
        int s, n;
        cin >> s >> n;
        vector<vector<int>> A(s, vector<int>(s, 1));
        for (int i = 0; i < n; i++) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            for (int x = r1-1; x <= r2-1; x++) {
                for (int y = c1-1; y <= c2-1; y++) {
                    A[x][y] = 0;
                }
            }
        }

        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                if (j > 0) A[i][j] += A[i][j-1];
            }
        }

        int maxSubRect = 0;
        for (int l = 0; l < s; l++) {
            for (int r = l; r < s; r++) {
                int subRect = 0;
                for (int row = 0; row < s; row++) {
                    int t = 0;
                    if (l > 0) t = A[row][r] - A[row][l-1];
                    else t = A[row][r];

                    if (t != r - l + 1) {
                        subRect = 0;
                        continue;
                    }

                    subRect += t;
                    maxSubRect = max(maxSubRect, subRect);
                }
            }
        }
        cout << maxSubRect << "\n";
    }
}