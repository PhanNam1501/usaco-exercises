#include<bits/stdc++.h>
using namespace std;

void tower(int n, int from, int mid, int to, vector<vector<int>> &res) {
    if (n == 1) {
        res.push_back(vector<int>{from, to});
        return;
    }
    tower(n-1, from, to, mid, res);
    res.push_back(vector<int>{from, to});
    tower(n-1, mid, from, to, res);

}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> res{};
    tower(n,  1, 2, 3, res);
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << " " << res[i][1] << "\n";
    }
}