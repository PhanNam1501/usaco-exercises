#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int x, y;
        cin >> x >> y;

        if (x == y) {
            if (x % 3 == 0) {
                cout << "YES" << "\n";
                continue;
            }
            
            cout << "NO" << "\n";
        } else {
            int maxx = max(x, y);
            int sub = x > y ? x - y : y - x;

            int res = maxx - 2 * sub;
            if (res < 0) {
                cout << "NO" << "\n";
                continue;
            }
            if (res % 3 == 0) {
                cout << "YES" << "\n";
                continue;
            }
            cout << "NO" << "\n";
        }
    }
}