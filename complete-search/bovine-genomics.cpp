#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read from input file
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    // Parse input
    int N, M;
    cin >> N >> M;

    vector<vector<char>> arr(2 * N, vector<char>(M));

    for (int i = 0; i < 2 * N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j];
        }
    }

    int res = 0;

    for (int i = 0; i < M; i++) {
        map<int, bool> mp;
        int cnt = 0;
        for (int j = 0; j < 2*N; j++) {
            if (j < N) {
                mp[arr[j][i]] = true;
            } else {
                if (mp[arr[j][i]] == false) {
                    cnt++;
                }
            }
        }
        if (cnt == N) {
            res++;
        }
    }

    cout << res << "\n";

    return 0;
}
