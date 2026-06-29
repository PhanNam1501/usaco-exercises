#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        long long summ = 0;
        for (int i = 0; i < N; i++) summ += arr[i];

        if (summ == 0) {
            cout << 0 << "\n";
            continue;
        }

        vector<long long> divs;
        for (long long i = 1; i * i <= summ; i++) {
            if (summ % i == 0) {
                divs.push_back(i);
                if (i != summ / i) divs.push_back(summ / i);
            }
        }

        int res = INT_MAX;
        for (long long d : divs) {
            long long c = 0;
            int segments = 0;
            bool f = false;

            for (int j = 0; j < N; j++) {
                if ((long long)arr[j] > d) { f = true; break; }
                c += arr[j];
                if (c == d) {
                    segments++;
                    c = 0;
                } else if (c > d) {
                    f = true;
                    break;
                }
            }

            if (c != 0) f = true;

            if (!f) {
                res = min(res, N - segments);
            }
        }

        cout << res << "\n";
    }

    return 0;
}