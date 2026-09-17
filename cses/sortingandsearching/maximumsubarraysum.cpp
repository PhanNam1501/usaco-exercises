#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<long long> pre(n+1, 0);
    long long minn = LONG_LONG_MAX;
    long long res = arr[0];
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + arr[i-1];
        if (minn != LONG_LONG_MAX) {
            res = max(res, max(pre[i], pre[i] - minn));
        }
        minn = min(minn, pre[i]);
    }
    

    cout << res << "\n";
}