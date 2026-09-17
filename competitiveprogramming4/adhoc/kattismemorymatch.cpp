#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<pair<int, int>> scores(K);
    vector<pair<string, string>> words(K);
    for (int i = 0; i < K; i++) {
        int x, y;
        string z, k;
        cin >> x >> y >> z >> k;

        scores[i].first = x;
        scores[i].second = y;
        words[i].first = z;
        words[i].second = k;
    } 
    int res = 0;
    unordered_map<string, bool> coupled;
    unordered_map<string, int> mp;
    int remembers = 0;

    for (int i = 0; i < K; i++) {
        if (words[i].first != words[i].second) {
            if (!coupled[words[i].first]) {
                if (mp[words[i].first] != 0 && scores[i].first != mp[words[i].first]) {
                    coupled[words[i].first] = true; 
                    res++;
                } else if (mp[words[i].first] == 0) {
                    remembers++;
                    mp[words[i].first] = scores[i].first;
                }
            }

            if (!coupled[words[i].second]) {
                if (mp[words[i].second] != 0 && scores[i].second != mp[words[i].second]) {
                    coupled[words[i].second] = true; 
                    res++;
                } else if (mp[words[i].second] == 0) {
                    remembers++;
                    mp[words[i].second] = scores[i].second;
                }
            }
        } else {
            if (mp[words[i].second] == 0) remembers++;
            if (coupled[words[i].first]) continue;
            coupled[words[i].first] = true;
            res++;
        }
    }

    if (remembers == N/2 && res < remembers) res++; 
    cout << res << "\n";
}