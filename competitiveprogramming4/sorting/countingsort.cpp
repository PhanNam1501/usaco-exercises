#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int L = INT_MAX;
    int R = INT_MIN;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        L = min(L, arr[i]);
        R = max(R, arr[i]);
    }
    int k = R - L + 1;
    vector<int> f(k);
    for (int i = 0; i < n; i++) {
        f[arr[i]-L]++;
    }
    vector<int> pre(k);
    for (int i = 0; i < k; i++) {
        if (i == 0) pre[i] = f[0];
        else pre[i] = f[i] + pre[i-1];
    }

    vector<int> res(n);
    for (int i = n-1; i >= 0; i--) {
        res[pre[arr[i]-L]-1] = arr[i];
        pre[arr[i]-L]--;
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
}
