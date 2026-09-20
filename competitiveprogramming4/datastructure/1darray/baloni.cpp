#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (mp[arr[i]] == 0) {
            res++;
            mp[arr[i]-1]++;
        } else {
            mp[arr[i]]--;
            mp[arr[i]-1]++;
        }
    }

    cout << res << "\n";
}