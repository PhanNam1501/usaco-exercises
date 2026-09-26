#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> res;
vector<int> curr;
vector<bool> row_used(8, false);
vector<bool> leftcross(15, false);
vector<bool> rightcross(15, false);

void backtrack(int col) {
    if (col == 8) {
        res.push_back(curr);
        return;
    }

    for (int row = 0; row < 8; row++) {
        if (!row_used[row] && !leftcross[row - col + 7] && !rightcross[col + row]) {
            row_used[row] = true;
            leftcross[row - col + 7] = true;
            rightcross[col + row] = true;
            curr.push_back(row + 1);
            
            backtrack(col + 1);
            
            row_used[row] = false;
            leftcross[row - col + 7] = false;
            rightcross[col + row] = false;
            curr.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    backtrack(0);

    int t;
    if (!(cin >> t)) return 0;

    for (int tc = 0; tc < t; tc++) {
        int r, c;
        cin >> r >> c;

        if (tc > 0) {
            cout << "\n";
        }

        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";

        int cnt = 1;
        for (const auto& sol : res) {
            if (sol[c - 1] == r) {
                cout << setw(2) << cnt << "      ";
                for (int k = 0; k < 8; k++) {
                    cout << sol[k] << (k == 7 ? "" : " ");
                }
                cout << "\n";
                cnt++;
            }
        }
    }

    return 0;
}