#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    long long summ = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > summ+1) {
            cout << summ+1 << "\n";
            return 0;
        }

        summ += arr[i];
    }

    cout << summ + 1;
}