#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> &arr, int k) {
    int l = 0;
    int r = arr.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] <= k) l = m + 1;
        else r = m;
    }
    return l;
}

int main() {
    int P;
    cin >> P;
    while (P--) {
        int K;
        cin >> K;
        vector<int> arr(20);
        for (int i = 0; i < 20; i++) {
            cin >> arr[i];
        }
        int res = 0;
        vector<int> samp{};
        for (int i = 0; i < 20; i++) {
            if (i == 0) {
                samp.push_back(arr[i]);
            } else {
                sort(samp.begin(), samp.end());
                int t = bs(samp, arr[i]);
                res += (samp.size()-t);
                samp.push_back(arr[i]);
            }
        }
        cout << K << " ";
        cout << res << "\n";
    }
}