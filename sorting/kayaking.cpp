#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> w(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> w[i];

    sort(w.begin(), w.end());

    int ans = INT_MAX;

    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {

            int cur = 0;
            vector<int> remain;

            for (int k = 0; k < 2 * n; k++) {
                if (k != i && k != j)
                    remain.push_back(w[k]);
            }

            for (int k = 0; k < remain.size(); k += 2) {
                cur += remain[k + 1] - remain[k];
            }

            ans = min(ans, cur);
        }
    }

    cout << ans << "\n";
    return 0;
}