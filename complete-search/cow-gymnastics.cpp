#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read from input file
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    // Parse input
    int K, N;
    cin >> K >> N;

    vector<vector<int>> arr(K, vector<int>(N, 0));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    map<int, map<int, bool>> mp;
    vector<vector<int>> res(N+1);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N-1; j++) {
            for (int k = j+1; k < N; k++) {
                if (!mp[arr[i][j]][arr[i][k]]) {
                    res[arr[i][j]].push_back(arr[i][k]);
                }
                mp[arr[i][j]][arr[i][k]] = true;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < res[i].size(); j++) {
            if (mp[res[i][j]][i]) {
                continue;
            }
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}
