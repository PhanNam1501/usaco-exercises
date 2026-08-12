#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

bool isSquare(int n) {
    int x = sqrt(n);
    return x * x == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    arr.resize(6);

    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }

    int s = 0;
    for (int i = 0; i < 6; i+= 2) {
        s += arr[i] * arr[i+1];
    }
    
    if (!isSquare(s)) {
        cout << -1 << "\n";
        return 0;
    }

    int n = (int)round(sqrt(s));
    
    vector<vector<int>> p(3);
    for (int i = 0; i < 3; i++) {
        p[i] = vector<int>{arr[2*i], arr[2*i+1]};
    }

    // Case 1: 3 logo xếp thành 3 hàng ngang
    int l = 0, r = 0;
    bool check = true;
    for (int i = 0; i < 3; i++) {
        if (p[i][0] > p[i][1]) {
            if (l == 0) {
                l = p[i][0];
                r += p[i][1];
            } else if (l == p[i][0]) {
                r += p[i][1];
            } else {
                check = false;
                break;
            }
        } else {
            if (l == 0) {
                l = p[i][1];
                r += p[i][0];
            } else if (l == p[i][1]) {
                r += p[i][0];
            } else {
                check = false;
                break;
            }
        }
    }
    if (check && l == r) {
        cout << n << "\n";
        for (int i = 0; i < 3; i++) {
            int a = 0, b = 0;
            if (p[i][0] > p[i][1]) { a = p[i][0]; b = p[i][1]; }
            else                    { a = p[i][1]; b = p[i][0]; }
            string lab = "A";
            if (i == 1) lab = "B";
            if (i == 2) lab = "C"; // sửa bug == thành =
            for (int j = 0; j < b; j++) {
                for (int k = 0; k < a; k++) cout << lab;
                cout << "\n";
            }
        }
        return 0;
    }

    int idx[3] = {0, 1, 2};
    do {
        int solo = idx[0], left = idx[1], right = idx[2];
        for (int rs = 0; rs < 2; rs++)
        for (int rl = 0; rl < 2; rl++)
        for (int rr = 0; rr < 2; rr++) {
            int ws = rs ? p[solo][1] : p[solo][0];
            int hs = rs ? p[solo][0] : p[solo][1];
            int wl = rl ? p[left][1] : p[left][0];
            int hl = rl ? p[left][0] : p[left][1];
            int wr = rr ? p[right][1] : p[right][0];
            int hr = rr ? p[right][0] : p[right][1];

            if (ws == n && wl + wr == n && hl == n - hs && hr == n - hs) {
                cout << n << "\n";
                string ls(1, 'A' + solo);
                string ll(1, 'A' + left);
                string lr(1, 'A' + right);
                for (int row = 0; row < hs; row++) {
                    for (int c = 0; c < n; c++) cout << ls;
                    cout << "\n";
                }
                for (int row = 0; row < hl; row++) {
                    for (int c = 0; c < wl; c++) cout << ll;
                    for (int c = 0; c < wr; c++) cout << lr;
                    cout << "\n";
                }
                return 0;
            }
        }
    } while (next_permutation(idx, idx + 3));

    cout << -1 << "\n";
    return 0;
}