#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = pair<int, int>{x, y};
    }

    sort(arr.begin(), arr.end());

    int res = 0;
    for (int i = 0; i < N; i++) {
        if (res >= arr[i].first) {
            res += arr[i].second;
        } else {
            res = arr[i].first + arr[i].second;
        }
    }

    cout << res << "\n";
}