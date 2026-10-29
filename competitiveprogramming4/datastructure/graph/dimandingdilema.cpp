#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> col(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                if (x == 1) {
                    col[j].push_back(i);
                }
            }
        }

        int check = true;
        for (int i = 0; i < m; i++) {
            if (col[i].size() != 2) {
                check = false;
                break;
            }
        }

        if (!check) {
            cout << "No\n";
        } else {
            bool valid = true;
            unordered_map<int, unordered_map<int, bool>> mp;
            for (int i = 0; i < m; i++) {
                if (mp[col[i][0]][col[i][1]] || mp[col[i][1]][col[i][0]]) {
                    valid = false;
                    break;
                }
                mp[col[i][0]][col[i][1]] = true;
                mp[col[i][1]][col[i][0]] = true;
            }
            if (!valid) cout << "No\n";
            else cout << "Yes\n";
        }
    }
}