#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        if (s == "") return 0;
        vector<pair<int, int>> arr;
        int prev = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'X') {
                arr.push_back(pair<int,int>{prev, i});
                prev = i;
            }
        }
        arr.push_back(pair<int, int>{prev, s.size()});

        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].first == -1) {
                res = max(res, arr[i].second - 1);
            } else if (arr[i].second == s.size()) {
                res = max(res, arr[i].second - arr[i].first - 2);
            } else {
                res = max(res, (arr[i].second - arr[i].first - 2) / 2);

            }
        }

        cout << res << "\n";
    }
}