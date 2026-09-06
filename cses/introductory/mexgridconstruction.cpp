#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = i ^ j;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

}