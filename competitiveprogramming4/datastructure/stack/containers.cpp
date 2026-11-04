#include<bits/stdc++.h>
using namespace std;

int main() {
    int cases = 1;
    while (true) {
        string s;
        cin >> s;
        if (s == "end") break;
        vector<bool> arr(26);
        int ext = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!arr[int(s[i]-'A')]) {
                arr[int(s[i]-'A')] = true;
                ext++; 
            }
        }
        vector<char> res;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) res.push_back(s[i]);
            else {
                int minn = INT_MAX;
                int idx = -1;
                for (int j = 0; j < res.size(); j++) {
                    if (s[i] <= res[j]) {
                        if (int(res[j] - s[i]) < minn) {
                            minn = int(res[j] - s[i]);
                            idx = j;
                        }
                    }
                }
                if (minn != INT_MAX) {
                    res[idx] = s[i];
                } else {
                    res.push_back(s[i]);
                }
            }
        }

        cout << "Case " << cases << ": " << min(int(res.size()), ext) << "\n";
        cases++;
    }
}