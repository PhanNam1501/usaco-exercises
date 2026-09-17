#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int x) {
    if (x < 0) return -1;
    if (parent[x] == x) {
        return x;
    }

    return parent[x] = find(parent, parent[x]);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> t(m);
    for (int i = 0; i < m; i++)
        cin >> t[i];

    sort(h.begin(), h.end());

    vector<int> parent(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int price : t) {

        int r = upper_bound(h.begin(), h.end(), price) - h.begin();

        int idx = find(parent, r - 1);

        if (idx == -1) {
            cout << -1 << '\n';
            continue;
        }

        cout << h[idx] << '\n';

        parent[idx] = find(parent, idx - 1);
    }
}