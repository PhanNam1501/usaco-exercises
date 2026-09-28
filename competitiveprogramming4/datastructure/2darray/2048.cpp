#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rot(vector<vector<int>> a) {
    auto b = a;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            b[j][3 - i] = a[i][j];
    return b;
}

vector<int> slide(vector<int> row) {
    vector<int> v, res;
    for (int x : row) if (x) v.push_back(x);
    for (int i = 0; i < v.size(); i++) {
        if (i + 1 < v.size() && v[i] == v[i + 1]) {
            res.push_back(v[i] * 2);
            i++;
        } else {
            res.push_back(v[i]);
        }
    }
    res.resize(4, 0);
    return res;
}

int main() {
    vector<vector<int>> a(4, vector<int>(4));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) cin >> a[i][j];
    int d; cin >> d;

    for (int i = 0; i < (4 - d) % 4; i++) a = rot(a);
    for (int i = 0; i < 4; i++) a[i] = slide(a[i]);
    for (int i = 0; i < d; i++) a = rot(a);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) cout << a[i][j] << (j == 3 ? "" : " ");
        cout << "\n";
    }
}