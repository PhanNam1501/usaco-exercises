// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read from input file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Parse input
    int N, B;
    cin >> N >> B;

    vector<pair<int,int>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    // if (B % 2 == 0) {
    //     B--;
    // }

    int res = 0;

    for (int i = 0; i < N; i++) {
        int a = arr[i].first + 1;

        for (int j = 0; j < N; j++) {
            int b = arr[j].second + 1;

            int g1 = 0, g2 = 0, g3 = 0, g4 = 0;

            for (int k = 0; k < N; k++) {
                if (arr[k].first > a && arr[k].second < b)
                    g1++;
                else if (arr[k].first > a && arr[k].second > b)
                    g2++;
                else if (arr[k].first < a && arr[k].second < b)
                    g3++;
                else
                    g4++;
            }

            int maxx = max({g1, g2, g3, g4});
            res = (res == 0 ? maxx : min(res, maxx));
        }
    }

    // Solution here
    cout << res << "\n";

    return 0;
}

