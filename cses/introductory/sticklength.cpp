#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<long long> pre(n, 0);
    for (int i = 0; i < n; i++) {
        if (i == 0) pre[i] = arr[i];
        else pre[i] = pre[i-1] + arr[i];
    }

    sort(arr.begin(), arr.end());
    long long res = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        long long t = (i+1) * arr[i] - pre[i] + pre[n-1] - pre[i] - ((n-i-1) * arr[i]);
        res = min(res, t);
    }

    cout << res << "\n";
}