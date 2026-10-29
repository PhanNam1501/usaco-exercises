#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        
        vector<vector<int>> AM(1000001);
        for (int i = 0; i < n; i++) {
            AM[arr[i]].push_back(i);
        }

        while (m--) {
            int k, v;
            cin >> k >> v;
            
            if (k > AM[v].size()) {
                cout << 0 << "\n";
            } else {
                cout << AM[v][k - 1] + 1 << "\n";
            }
        }
    }
    return 0;
}