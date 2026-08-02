#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int res = 1;
    for (int i = 0; i < N; i++) {
        if (i > 0 && arr[i] != arr[i-1]) {
            res += 1;
        }
    }

    cout << res << "\n";
}