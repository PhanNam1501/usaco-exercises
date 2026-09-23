#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int l = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        while (l < i && arr[l] + 1000 <= arr[i]) {
            l++;
        }

        int active = i - l + 1;
        int servers = (active + k - 1) / k;

        ans = max(ans, servers);
    }

    cout << ans << '\n';
}