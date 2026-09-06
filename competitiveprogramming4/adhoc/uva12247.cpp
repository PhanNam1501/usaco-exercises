#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> c, vector<int> p) {
    sort(p.begin(), p.end());

    do {
        sort(c.begin(), c.end());
        bool princess_can_win = false;

        do {
            int c_win = 0;
            for (int i = 0; i < 3; i++) {
                if (c[i] > p[i]) c_win++;
            }
            if (c_win >= 2) {
                princess_can_win = true;
                break;
            }
        } while (next_permutation(c.begin(), c.end()));

        if (princess_can_win) return false;

    } while (next_permutation(p.begin(), p.end()));

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        vector<int> x(3), y(2);
        cin >> x[0] >> x[1] >> x[2] >> y[0] >> y[1];

        if (x[0] == 0 && x[1] == 0 && x[2] == 0 && y[0] == 0 && y[1] == 0) {
            break;
        }

        vector<bool> used(53, false);
        for (int v : x) used[v] = true;
        for (int v : y) used[v] = true;

        int ans = -1;
        for (int z = 1; z <= 52; z++) {
            if (used[z]) continue;

            vector<int> prince = {y[0], y[1], z};
            if (check(x, prince)) {
                ans = z;
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}