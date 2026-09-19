#include<bits/stdc++.h>
using namespace std;

int recur(int x, int y, vector<int>& arr, vector<vector<int>>& dp) {
    if (x == y-1) {
        return arr[x-1] * arr[x] * arr[y];
    }

    int t1 = dp[x][y-1];
    if (t1 == -1) {
        t1 = recur(x, y-1, arr, dp);
    }
    int t2 = dp[x+1][y];
    if (t2 == -1) {
        t2 = recur(x+1, y, arr, dp);
    }

    int res1 = t1 + arr[x-1] * arr[y-1] * arr[y];
    int res2 = t2 + arr[x-1] * arr[x] * arr[y];  
    return min(res1, res2);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (n <= 2) {
        cout << 0;
        return 0;
    }
    cout << recur(1, n-1, arr, dp);

}