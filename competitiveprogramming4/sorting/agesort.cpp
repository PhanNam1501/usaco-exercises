#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> arr(n);
        int L = INT_MAX;
        int R = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            L = min(L, arr[i]);
            R = max(R, arr[i]);
        }
        int k = R - L + 1;
        vector<int> freq(k);
        for (int i = 0; i < n; i++) {
            freq[arr[i]-L]++;
        }

        vector<int> pre(k);
        for (int i = 0; i < k; i++) {
            if (i == 0) pre[0] = freq[0];
            else pre[i] = freq[i] + pre[i-1];
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[pre[arr[i]-L]-1] = arr[i];
            pre[arr[i]-L]--;
        }

        for (int i = 0; i < n; i++) {
            if (i == n-1) cout << res[i] << "\n";
            else cout << res[i] << " ";
        }
    }
}
