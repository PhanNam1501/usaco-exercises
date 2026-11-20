#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        long long t1 = (arr[N-1] - arr[i])/2;
        long long t2 = (i > 0 && i < N-1) ? (arr[i+1] - arr[0])/2 : 0;
        long long res1 = max(t1, t2) == 0 ? LONG_LONG_MAX : max(t1, t2);

        t1 = i > 0 ? (arr[i] - arr[0])/2 : 0;
        t2 = (i > 0 && i < N-1) ? (arr[N-1] - arr[i-1])/2 : 0;
        long long res2 = max(t1, t2) == 0 ? LONG_LONG_MAX : max(t1, t2);

        if (min(res1, res2) == LONG_LONG_MAX) {
            cout << 0 << "\n";
        } else {
            cout << min(res1, res2) << "\n";
        }

        
    }
}