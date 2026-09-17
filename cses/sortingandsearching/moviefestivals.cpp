#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    int res = 0;
    int endingtime = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            res++;
            endingtime = arr[i].second;
        } else {
            if (arr[i].first >= endingtime) {
                res++;
                endingtime = arr[i].second;
            }
        }
    }

    cout << res << "\n";
}