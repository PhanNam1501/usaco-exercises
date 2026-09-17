#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, key;
    if (!(cin >> n >> key)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (arr[0] > key) {
        cout << 0 << "\n";
        return 0;
    }

    int l = 0, r = n - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] > arr[r]) l = m + 1;
        else r = m;
    }
    int minidx = l;

    if (minidx == 0) {
        l = 0;
        r = n;
    } else if (key >= arr[0]) {
        l = 0;
        r = minidx;
    } else {
        l = minidx;
        r = n;
    }

    int limit = r;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] <= key) l = m + 1;
        else r = m;
    }

    if (l == limit) {
        cout << -1 << "\n";
    } else {
        cout << l << "\n";
    }

    return 0;
}