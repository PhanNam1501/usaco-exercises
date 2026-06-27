#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<string> arr(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> arr[i];
    }

    int res = 0;

    // key -> tập các chuỗi của bò Spotty
    map<int, set<string>> mp;

    // Lưu tất cả các chuỗi của Spotty
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {

                int key = i * M * M + j * M + k;

                for (int z = 0; z < N; z++) {
                    string value;
                    value += arr[z][i];
                    value += arr[z][j];
                    value += arr[z][k];

                    mp[key].insert(value);
                }
            }
        }
    }

    // Kiểm tra bò Plain
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {

                int key = i * M * M + j * M + k;

                bool ok = true;

                for (int z = N; z < 2 * N; z++) {

                    string value;
                    value += arr[z][i];
                    value += arr[z][j];
                    value += arr[z][k];

                    if (mp[key].count(value)) {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                    res++;
            }
        }
    }

    cout << res << '\n';

    return 0;
}