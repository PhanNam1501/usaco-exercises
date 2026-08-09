#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> str(N);
    vector<string> state(N);
    for (int i = 0; i < N; i++) {
        cin >> str[i];
        cin >> state[i];
    }   
    map<pair<string, string>, int> cnt; // map pre-> state -> cnt
    for (int i = 0; i < N; i++) {
        cnt[{str[i].substr(0,2), state[i]}]++;
    }
    long long res = 0;
    for (auto [p, c]: cnt) {
        auto [a, b] = p;
        res += 1LL * c * cnt[{b, a}];
    }

    cout << res / 2 << "\n";
}