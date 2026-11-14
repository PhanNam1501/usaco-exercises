#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        vector<int> pre(N, -1);
        vector<int> suf(N, -1);
        vector<int> L(N);
        int k = 0;
        for (int i = 0; i < N; i++) {
            int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
            L[pos] = A[i];
            
            if (pos == k) {
                k += 1;
            }

            pre[i] = pos;
        }
        k = 0;
        L = vector<int>(N);
        reverse(A.begin(), A.end());
        for (int i = 0; i < N; i++) {
            int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
            L[pos] = A[i];

            if (pos == k) {
                k += 1;
            }

            suf[i] = pos;
        }

        int res = 0;
        for (int i = 0; i < N; i++) {
            if (pre[i] != -1 && suf[N-1-i] != -1) {
                res = max(res, min(pre[i], suf[N-1-i]) * 2 + 1);
            }
        }

        cout << res << "\n";
    }
}