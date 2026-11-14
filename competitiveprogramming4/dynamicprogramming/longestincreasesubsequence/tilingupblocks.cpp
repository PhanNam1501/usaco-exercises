#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) {
            cout << "*\n";
            break;
        }
        vector<pair<int, int>> blocks(N);
        for (int i = 0; i < N; i++) {
            cin >> blocks[i].first >> blocks[i].second;
        }

        sort(blocks.begin(), blocks.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        vector<int> A(N);
        int k = 0; // size of lis
        vector<int> L(N);
        for (int i = 0; i < N; i++) {
            A[i] = blocks[i].second;
        }

        for (int i = 0; i < N; i++) {
            int pos = upper_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
            L[pos] = A[i];
            if (k == pos) {
                k = pos + 1;
            }
        }

        cout << k << "\n";
    }
}