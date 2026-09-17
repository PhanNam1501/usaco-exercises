#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, key;
    cin >> n >> key;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0;
    int r = n - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] <= key) l = m;
        else r = m - 1;
    }

    cout << l << "\n";
}