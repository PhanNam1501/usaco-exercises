#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int l = 0; int r = 0;
    int res = 0;
    while (l < n && r < m) {
        if (abs(a[l] - b[r]) <= k) {
            res++;
            l++;
            r++;
        } else {
            if (a[l] <= b[r]) l++;
            else r++;
        }
    }

    cout << res << "\n";
}