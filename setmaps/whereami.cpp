#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    map<string, bool> mp;

    for (int i = 1; i <= N; i++) {
        bool invalid = false;
        for (int j = 0; j < s.size() - i + 1; j++) {
            string t = s.substr(j, i);
            if (mp[t]) {
                invalid = true;
                break;
            }
            mp[t] = true;
        }
        if (!invalid) {
            cout << i << "\n";
            break;
        }
    }
    
}