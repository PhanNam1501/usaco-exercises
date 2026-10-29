#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] -= P;
    }

    int ans = 0;
    int summ = 0;
    for (int i = 0; i < N; i++) {
        summ += arr[i];
        if (summ < 0) summ = 0;
        ans = max(ans, summ);
    }
    cout << ans;
}