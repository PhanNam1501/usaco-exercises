#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> pre(N + 2, 0);
    vector<int> suf(N + 2, 0);

    for (int i = 1; i <= N; i++) {
        pre[i] = gcd(pre[i - 1], arr[i - 1]);
    }

    for (int i = N; i >= 1; i--) {
        suf[i] = gcd(suf[i + 1], arr[i - 1]);
    }

    int res = 0;

    for (int i = 1; i <= N; i++) {
        int cur = gcd(pre[i - 1], suf[i + 1]);
        res = max(res, cur);
    }

    cout << res << '\n';

    return 0;
}