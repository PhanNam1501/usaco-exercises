#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> pre(n);
    vector<int> suf(n);
    int minn = INT_MAX;
    int maxx = -1 * INT_MAX;

    for (int i = 0; i < n; i++) {
        maxx = max(maxx, arr[i]);
        pre[i] = maxx;
    }

    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) {
            suf[i] = minn;
            continue;
        }
        minn = min(minn, arr[i+1]);
        suf[i] = minn;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= pre[i] && arr[i] < suf[i]) {
            res++;
        }
    }
    cout << res << "\n";
}