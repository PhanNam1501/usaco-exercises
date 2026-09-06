#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    int cases = 1;
    while (t--) {
        vector<string> arr(52);
        for (int i = 0; i < 52; i++) {
            cin >> arr[i];
        }
        int y = 0;
        vector<string> pile(arr.begin() + 25, arr.end());
        reverse(pile.begin(), pile.end());
        int times = 3;
        int p = 0;
        while (times--) {
            int x = 0;

            if (int(pile[p][0] - '0') <= 9) {
                x = int(pile[p][0] - '0');
            } else {
                x = 10;
            }

            y += x;
            p += 11 - x;
        }

        int remain = 27 - p;
        if (y <= remain) {
            cout << "Case " << cases << ": " << pile[p + (remain-y)];
        } else {
            cout << "Case " << cases << ": " << arr[27 + (y - remain - 1)];
        }
        cout << "\n";
        cases++;

    }
}