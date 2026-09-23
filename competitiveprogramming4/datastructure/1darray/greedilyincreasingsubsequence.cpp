#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int prev = 0;
    int cnt = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            prev = arr[i];
            cnt++;
            res.push_back(arr[i]);
        } else {
            if (arr[i] > prev) {
                prev = arr[i];
                cnt++;
                res.push_back(arr[i]);
            }
        }
    }

    cout << cnt << "\n";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}