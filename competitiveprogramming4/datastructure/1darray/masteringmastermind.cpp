#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int r = 0;
    int s = 0;
    unordered_map<char, vector<int>> mp;
    unordered_map<int, bool> check;
    for (int i = 0; i < n; i++) {
        mp[s1[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (!check[i] && s1[i] == s2[i]) {
            check[i] = true;
            r++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (mp[s2[i]].size() == 0) continue;
        if (s1[i] == s2[i]) continue;
        vector<int> t = mp[s2[i]];
        for (int j = 0; j < t.size(); j++) {
            if (!check[t[j]]) {
                s++;
                check[t[j]] = true;
                break;
            }
        }
        
    }

    cout << r << " " << s << "\n";
}