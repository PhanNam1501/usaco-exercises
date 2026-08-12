#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<vector<int>> cowpos;
vector<int> cost;
vector<vector<int>> airpos;
vector<int> aircool;
vector<int> airprice;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    cowpos.resize(N);
    cost.resize(N);
    airpos.resize(M);
    aircool.resize(M);
    airprice.resize(M);

    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        cowpos[i] = (vector<int>{x, y});
        cost[i] = z;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        airpos[i] = vector<int>{a, b};
        aircool[i] = c;
        airprice[i] = d;
    }

    int res = INT_MAX;

    for (int mask = 0; mask < 1 << M; mask++) {
        vector<int> cool(101, 0);
        int price = 0;
        for (int i = 0; i < M; i++) {
            if ((mask & (1 << i))) {
                for (int pos = airpos[i][0]; pos <= airpos[i][1]; pos++) {
                    cool[pos] += aircool[i];
                }
                price += airprice[i];
            }
        }
        int check = true;
        for (int i = 0; i < N; i++) {
            for (int j = cowpos[i][0]; j <= cowpos[i][1]; j++) {
                if (cool[j] < cost[i]) {
                    check = false;
                    break;
                }
            }
        }
        if (check) {
            res = min(res, price);
        }
    }

    cout << res << "\n";

    return 0;
}