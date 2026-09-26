#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> pre(n+1, vector<int>(m+1, 0));

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (pre[i][j-1] >= pre[i-1][j]) {
                pre[i][j] = pre[i][j-1] + arr[i-1][j-1];
            } else {
                pre[i][j] = pre[i-1][j] + arr[i-1][j-1];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == n) {
            cout << pre[i][m] << "\n";
        } else {
            cout << pre[i][m] << " ";
        }
    }
}