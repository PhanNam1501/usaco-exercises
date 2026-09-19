#include<bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    int n = s.size();
    unordered_map<char, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }

    vector<char> res;
    for (int i = 0; i < n; i++) {
        bool valid = false;
        for (char x = 'A'; x <= 'Z'; x++) {
            if ((res.size() == 0 || x != res[res.size()-1]) && cnt[x] > 0) {
                cnt[x]--;
                int maxcount = 0;
                for (auto &[c, count]: cnt) {
                    maxcount = max(maxcount, count);
                }
                int remaining = n - i - 1;
                if (maxcount <= (remaining + 1) / 2) {
                    res.push_back(x);
                    valid = true;
                    break;
                } else {
                    cnt[x]++;
                }
            }
        }

        if (!valid) {
            cout << -1 << "\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i];
    }
    cout << "\n";
}