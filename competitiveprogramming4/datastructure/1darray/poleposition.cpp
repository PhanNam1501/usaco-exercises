#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }

        vector<int> startpos(n, -1);
        bool invalid = false;
        for (int i = 0; i < n; i++) {
            if (arr[i].second == 0) {
                if (startpos[i] != -1) {
                    cout << -1 << "\n";
                    invalid = true;
                    break;
                }
                startpos[i] = arr[i].first;
            } else if (arr[i].second > 0) {
                if (i + arr[i].second >= n || startpos[i + arr[i].second] != -1) {
                    cout << -1 << "\n";
                    invalid = true;
                    break;
                }
                startpos[i + arr[i].second] = arr[i].first;
            } else {
                if (i + arr[i].second < 0 || startpos[i + arr[i].second] != -1) {
                    cout << -1 << "\n";
                    invalid = true;
                    break;
                }
                startpos[i + arr[i].second] = arr[i].first;
            }
        }

        if (!invalid) {
            for (int i = 0; i < n; i++) {
                if (i > 0) cout << " ";
                cout << startpos[i];
            }
            cout << "\n";
        }
    }
}