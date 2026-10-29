#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int a = 0;
        int b = 0;
        int idx = 0;
        int cnt = 1;
        while(n) {
            int t = n & 1;
            n >>= 1;
            if (t == 1) {
                if (cnt % 2 == 1) {
                    a += 1 << idx;
                } else {
                    b += 1 << idx;
                }
                cnt++;
            }
            idx++;
        }
        cout << a << " " << b << "\n";
    }
}