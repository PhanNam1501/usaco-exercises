#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int n = pow(2, N);
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> potency(n);

        for (int i = 0; i < n; i++) {
            int summ = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int t = i ^ j;
                    int cnt = __builtin_popcount(t);
                    if (cnt == 1) {
                        summ += arr[j];
                    }
                }
            }
            potency[i] = summ;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int t = i ^ j;
                    int cnt = __builtin_popcount(t);
                    if (cnt == 1) {
                        res = max(res, potency[i] + potency[j]);
                    }
                }
            }
        }

        cout << res << "\n";
    }
}