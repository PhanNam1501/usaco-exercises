#include <bits/stdc++.h>
using namespace std;

// 2 2 2 2 2 2 2 2 50 2
const int MAXA = 200005;
int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> freq(MAXA, 0);
    vector<int> last(MAXA, 0);
    int blockstart = 0;
    int maxR = 0;
    int maxFre = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        last[arr[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        maxR = max(maxR, last[arr[i]]);
        maxFre = max(maxFre, freq[arr[i]]);

        if (i == maxR) {
            res += (i - blockstart + 1) - maxFre;
            blockstart = i+1;
            maxFre = 0;
        }
    }

    cout << res << "\n";
}
