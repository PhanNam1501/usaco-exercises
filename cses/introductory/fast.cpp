#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long x, y;
        cin >> x >> y;

        long long d = max(x, y);
        if (d == 1) cout << 1 << "\n";
        else if (d % 2LL == 0LL) {
            long long mock = d * d;
            mock -= (y-1)+(d-x);
            cout << mock << "\n";
        } else {
            long long mock = d * d;
            mock -= (x-1)+(d-y);
            cout << mock << "\n";
        }
    }
    
}