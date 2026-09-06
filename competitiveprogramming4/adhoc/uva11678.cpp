#include<bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;

        unordered_set<int> aset;
        for (int i = 0; i < a; i++) {
            int x;
            cin >> x;
            aset.insert(x);
        }

        unordered_set<int> bset;
        for (int i = 0; i < b; i++) {
            int x;
            cin >> x;
            bset.insert(x);
        }

        int resa = 0;
        int resb = 0;
        for (int x: aset) {
            if (!bset.count(x)) {
                resa++;
            }
        }
        for (int x: bset) {
            if (!aset.count(x)) {
                resb++;
            }
        }

        cout << min(resa, resb) << "\n";

    }
}