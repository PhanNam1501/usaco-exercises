#include<bits/stdc++.h>
using namespace std;


void backtrack(int n, int idx, vector<int> &res) {
    if (n == 0) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
        }
        cout << "\n";
        return;
    }

    if (idx % 2 == 0) {
        for (int i = 0; i <= 1; i++) {
            res.push_back(i);
            backtrack(n-1, idx*2+i, res);
            res.pop_back();
        }
    } else {
        for (int i = 1; i >= 0; i--) {
            res.push_back(i);
            backtrack(n-1, idx*2+(1-i), res);
            res.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> res{};
    backtrack(n, 0, res);
}