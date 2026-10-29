#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> x(N);
        unordered_map<int, bool> mp;
        for (int i = 0; i < N; i++) {
            cin >> x[i];
        }
        vector<int> a(Q);
        for (int i = 0; i < Q; i++) cin >> a[i];

        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < N; j++) {
                if (i & x[j] == i) {
                    mp[i] = true;
                    break;
                }
            }
        }
        
        for (int i = 0; i < Q; i++) {
            int maxx = 0;
            for (int j = 0; j < 256; j++) {
                if (mp[j]) {
                    maxx = max(maxx, a[i] & j);
                }
            }
            cout << maxx << "\n";
        }
    }
}