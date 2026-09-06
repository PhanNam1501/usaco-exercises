#include<bits/stdc++.h>
using namespace std;

int bs(vector<long long> &a, int k) {
    int l = 0;
    int r = a.size();

    while (l < r) {
        int m = l + (r - l) / 2;

        if (a[m] <= k) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    vector<long long> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        int t = bs(b, a[i]);
        if (t == 0) {
            res = max(res, b[0] - a[i]);
        } else if (t == m) {
            res = max(res, a[i] - b[m-1]);
        } else {
            res = max(res, min(b[t] - a[i], a[i] - b[t-1]));
        }
    }

    cout << res << "\n";


}