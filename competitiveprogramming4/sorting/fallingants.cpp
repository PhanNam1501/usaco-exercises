#include<bits/stdc++.h>
using namespace std;

struct Ant {
    int volume;
    int H;
};

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<Ant> ants(n);
        for (int i = 0; i < n; i++) {
            int l, w, h;
            cin >> l >> w >> h;
            Ant a = {l * w * h, h};
            ants[i] = a;
        }

        sort(ants.begin(), ants.end(), [](Ant a, Ant b) {
            if (a.H == b.H) {
                return a.volume < b.volume;
            }
            return a.H < b.H;
        });

        cout << ants[n-1].volume << "\n";
    }


}