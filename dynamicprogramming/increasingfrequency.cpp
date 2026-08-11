#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    int maxx = 0;
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxx = max(maxx, arr[i]);
    }

    vector<int> pre(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) pre[i] = 0;
        pre[i] = cnt;
        if (arr[i] == c) {
            cnt++;
        } 
    }

    if (cnt == n) {
        cout << n << "\n";
        return 0;
    }

    vector<vector<int>> pos(maxx+1, vector<int>{});
    for (int i = 0; i < n; i++) {
        if (arr[i] == c) continue;
        pos[arr[i]].push_back(i);
    }

    int res = 0;
    for (int i = 1; i <= maxx; i++) {
        if (pos[i].size() > 0) {
            vector<int> dp(pos[i].size()+1, 0);
            int r = 0;
            for (int j = 1; j <= pos[i].size(); j++) {
                int curr = 0;
                if (j > 1) {
                    curr = pre[pos[i][j-1]] - pre[pos[i][j-2]];
                } else {
                    curr = pre[pos[i][j-1]];
                }
                
                dp[j] = max(dp[j-1] + 1 - curr, 1);
                r = max(r, cnt + dp[j]);
            }
            res = max(res, r);
        }
    }

    cout << res << "\n";

}