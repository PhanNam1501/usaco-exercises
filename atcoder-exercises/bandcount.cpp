#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W, N, Q;
    cin >> H >> W >> N >> Q;
    vector<long long> row(N);
    vector<long long> col(N);
    for (int i = 0; i < N; i++) {
        long long r, c;
        cin >> r >> c;
        row[i] = r;
        col[i] = c;
    }

    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    for (int i = 0; i < Q; i++) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            auto it_start = lower_bound(row.begin(), row.end(), x);
            auto it_end = upper_bound(row.begin(), row.end(), y);
            cout << distance(it_start, it_end) << "\n";
        } else {
            auto it_start = lower_bound(col.begin(), col.end(), x);
            auto it_end = upper_bound(col.begin(), col.end(), y);
            cout << distance(it_start, it_end) << "\n";
        }
    }
}