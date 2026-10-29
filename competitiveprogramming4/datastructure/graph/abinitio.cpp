#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, Q;
    cin >> V >> E >> Q;

    vector<vector<bool>> AM(4005, vector<bool>(4005, false));

    for (int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        AM[x][y] = true;
    }

    bool istransposed = false;
    bool iscomplement = false;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            for (int i = 0; i < V; i++) {
                AM[V][i] = iscomplement;
                AM[i][V] = iscomplement;
            }
            AM[V][V] = false; 
            V++;
        } else if (type == 2) {
            int x, y;
            cin >> x >> y;
            if (istransposed) {
                swap(x, y);
            }
            AM[x][y] = !iscomplement;
        } else if (type == 3) {
            int x;
            cin >> x;
            for (int i = 0; i < V; i++) {
                AM[x][i] = iscomplement;
                AM[i][x] = iscomplement;
            }
        } else if (type == 4) {
            int x, y;
            cin >> x >> y;
            if (istransposed) {
                swap(x, y);
            }
            AM[x][y] = iscomplement;
        } else if (type == 5) {
            istransposed = !istransposed;
        } else if (type == 6) {
            iscomplement = !iscomplement;
        }
    }

    cout << V << "\n";

    long long MOD = 1e9 + 7;

    for (int i = 0; i < V; i++) {
        long long outdegree = 0;
        long long hash_val = 0;
        long long p = 1; 

        for (int j = 0; j < V; j++) {
            if (i == j) continue;

            bool has_edge = AM[i][j];
            if (istransposed) {
                has_edge = AM[j][i];
            }
            if (iscomplement) {
                has_edge = !has_edge;
            }

            if (has_edge) {
                outdegree++;
                hash_val = (hash_val + p * j) % MOD;
                p = (p * 7) % MOD;
            }
        }

        cout << outdegree << " " << hash_val << "\n";
    }

    return 0;
}