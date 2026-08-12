#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> arr;

long long recursive(int index, long long sum1, long long sum2) {
    if (index == n) {
        return abs(sum1 - sum2);
    }

    return min(recursive(index+1, sum1 + arr[index], sum2), recursive(index+1, sum1, sum2 + arr[index]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << recursive(0, 0, 0);
    return 0;
}