#include <bits/stdc++.h>
using namespace std;

bool isMoo(const string& t) {
    return t[0] != t[1] && t[1] == t[2];
}

int main() {
    int N, F;
    cin >> N >> F;

    string s;
    cin >> s;

    map<string, int> cnt;

    for (int i = 0; i + 2 < N; i++) {
        string t = s.substr(i, 3);

        if (isMoo(t)) {
            cnt[t]++;
        }
    }

    set<string> result;

    for (auto &[t, c] : cnt) {
        if (c >= F) {
            result.insert(t);
        }
    }

    for (int pos = 0; pos < N; pos++) {

        char old = s[pos];

        for (char c = 'a'; c <= 'z'; c++) {

            if (c == old) continue;
            vector<string> oldMoo;
            for (int start = max(0, pos - 2); start <= min(N-3, pos); start++) {
                string t = s.substr(start, 3);
                if (isMoo(t)) {
                    oldMoo.push_back(t);
                    cnt[t]--;
                }
            }
            s[pos] = c;
            vector<string> newMoo;
            for (int start = max(0, pos - 2); start <= min(N-3, pos); start++) {
                string t = s.substr(start, 3);
                if (isMoo(t)) {
                    newMoo.push_back(t);
                    cnt[t]++;
                }
            }

            for (auto &t : oldMoo) {
                if (cnt[t] >= F) {
                    result.insert(t);
                }
            }

            for (auto &t : newMoo) {
                if (cnt[t] >= F) {
                    result.insert(t);
                }
            }

            for (auto &t : newMoo) {
                cnt[t]--;
            }

            for (auto &t : oldMoo) {
                cnt[t]++;
            }

            s[pos] = old;

        }
    }

    cout << result.size() << '\n';

    for (auto &t : result) {
        cout << t << '\n';
    }
}