#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    while (cin >> m >> n) {
        vector<vector<pair<int, int>>> AM(n + 1);
        
        for (int row = 1; row <= m; row++) {
            int r;
            cin >> r;
            if (r == 0) continue;
            
            vector<int> col(r);
            for (int i = 0; i < r; i++) {
                cin >> col[i];
            }
            
            for (int i = 0; i < r; i++) {
                int val;
                cin >> val;
                AM[col[i]].push_back({row, val});
            }
        }

        cout << n << " " << m << "\n";
        
        for (int i = 1; i <= n; i++) {
            int sz = AM[i].size();
            if (sz == 0) {
                cout << 0 << "\n\n"; 
            } else {
                cout << sz << " ";
                for (int j = 0; j < sz; j++) {
                    cout << AM[i][j].first << (j == sz - 1 ? "\n" : " ");
                }
                for (int j = 0; j < sz; j++) {
                    cout << AM[i][j].second << (j == sz - 1 ? "\n" : " ");
                }
            }
        }
    }
    return 0;
}