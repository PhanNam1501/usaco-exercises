#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    long long res = 0;
    long long cost = 0;
    // int idx = 0;
    // for (int i = 1; i <= 1000000; i++) {
    //     if (i <= arr[idx]) {
    //         long long r = 1LL * i * (N - idx);
    //         if (r > res) {
    //             res = r;
    //             cost = i;
    //         }
    //         while (idx < N && i == arr[idx]) {
    //             idx++;
    //         }
    //         if (idx == N)
    //             break;
    //         }
    // }

    for (int i = 0; i < N; i++) {
        long long r = 1LL * arr[i] * (N - i);
        if (res < r) {
            res = r;
            cost = arr[i];
        }
    }

    cout << res << " " << cost << "\n";
}