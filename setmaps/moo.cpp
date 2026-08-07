#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    map<int, int> mp;
    // map<int, long long> frontdistinct;
    // map<int, int> first;
    // map<int, int> second;

    vector<int> frontdistinct(N + 1);
    vector<int> first(N + 1, -1);
    vector<int> second(N + 1, -1);
    long long cnt = 0;
    // for (int i = 0; i < N; i++) {
    //     mp[arr[i]]++;
    // }

    long long distinct = 0;
    for (int i = 0; i < N; i++) {
        int s = arr[i];
        if (mp[s] >= 1) {
            frontdistinct[i] = distinct-1;
        } else {
            frontdistinct[i] = distinct;
        }

        if (mp[s] == 0) {
            distinct++;
            first[s] = i;
        } else if (mp[s] == 1) { 
            second[s] = i;
        } else {
            first[s] = second[s];
            second[s] = i;
        }
        mp[s]++;
    }

    long long res = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second >= 2) {
            res += frontdistinct[first[it->first]];
        }
    }

    cout << res << "\n";
}
   