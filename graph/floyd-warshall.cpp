#include<bits/stdc++.h>
using namespace std;

const int INF = 99999;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1));
    vector<vector<int>> nxt(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];

            if (dist[i][j] == INF || dist[i][j] == 0) continue;
            nxt[i][j] = j;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == INF && dist[k][j] == INF) continue;

                int newDist = dist[i][k] + dist[k][j];
                if (newDist < dist[i][j]) {
                    dist[i][j] = newDist;
                    nxt[i][j] = k;
                }
            }
        }
    }

    cout << "Ma tran khoang cach:\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    cout << "\nCac duong di ngan nhat:\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (i == j) {
                continue;
            }

            if (dist[i][j] == INF) {
                cout << "Khong co duong di tu "
                     << i << " toi " << j << '\n';
                continue;
            }

            cout << "Duong " << i << " toi " << j << ": ";

            int current = i;

            while (current != j) {
                cout << current << " ";
                current = nxt[current][j];
            }

            cout << j << '\n';
        }
    }

    return 0;
}