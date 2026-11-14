#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<int, int> mp;
    unordered_map<int, int> prev_id;
    long long res = 0;
    int prev = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        mp[x]++;
        if (x == prev) {
            res += (long long)(i-prev_id[x]-1);
        } else {
            res += (long long)(i+1-mp[x]);
        }
        prev = x;
        prev_id[x] = i;
    }
    

    cout << res+1;
}