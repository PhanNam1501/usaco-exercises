#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

const int MAX_V = 2000;
int h, k;
int res = 0;
vector<int> curr;
vector<int> best_curr;

void backtrack(int n, int current_max) {
    if (n == k) {
        if (current_max > res) {
            res = current_max;
            best_curr = curr;
        }
        return; 
    }

    int prev = curr.empty() ? 0 : curr.back();

    for (int key = prev + 1; key <= current_max + 1; key++) {
        curr.push_back(key);

        vector<vector<bool>> dp(MAX_V, vector<bool>(h + 1, false));
        dp[0][0] = true; 
        int new_max = 0;

        for (int i = 1; i < MAX_V; i++) {
            bool can_make_i = false; 

            for (int j = 1; j <= h; j++) {
                for (auto &x : curr) {
                    if (x <= i && dp[i - x][j - 1]) {
                        dp[i][j] = true;
                        can_make_i = true;
                        break; 
                    }
                }
            }

            if (can_make_i) {
                new_max = i;
            } else {
                break; 
            }
        }

        backtrack(n + 1, new_max);

        curr.pop_back(); 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> h >> k && (h || k)) {
        res = 0;
        curr.clear();
        best_curr.clear();

        backtrack(0, 0);

        for (int x : best_curr) {
            cout << setw(3) << x;
        }
        cout << " ->" << setw(3) << res << "\n";
    }

    return 0;
}