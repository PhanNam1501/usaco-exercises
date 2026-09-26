#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, t, m;
    cin >> n >> t >> m;

    vector<vector<int>> arr1(m, vector<int>(2));
    vector<char> arr2(m);
    vector<string> arr3(m);

    for (int i = 0; i < m; i++) {
        int x, y;
        char z;
        string k;
        cin >> x >> y >> z >> k;
        arr1[i] = vector<int>{x, y};
        arr2[i] = z;
        arr3[i] = k;
    }

    unordered_map<char, vector<int>> res;
    unordered_map<char, unordered_map<int, bool>> solved;
    for (int i = 0; i < m; i++) {
        if (arr3[i] == "Yes") {
            if (res[arr2[i]].size() == 0 || (res[arr2[i]].size() > 0 && res[arr2[i]][1] != arr1[i][1] && !solved[arr2[i]][arr1[i][1]])) {
                res[arr2[i]] = vector<int>{arr1[i][0], arr1[i][1]};
                solved[arr2[i]][arr1[i][1]] = true; 
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (res[char('A' + i)].size() == 0) {
            cout << char('A' + i) << " " << "-" << " " << "-" << "\n";
        } else {
            cout << char('A' + i) << " " << res[char('A' + i)][0] << " " << res[char('A' + i)][1] << "\n";
        }
    }
}