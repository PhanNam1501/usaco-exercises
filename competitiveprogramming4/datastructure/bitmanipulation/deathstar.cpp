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

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i] |= arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == n-1) cout << res[i] << "\n";
        else cout << res[i] << " ";
    }
}