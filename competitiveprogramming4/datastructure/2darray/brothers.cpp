#include<bits/stdc++.h>
using namespace std;

vector<int> dx{-1, 1, 0, 0};
vector<int> dy{0, 0, -1, 1};

int main() {
    int N, R, C, K;

    while (cin >> N >> R >> C >> K) {
        if (N == 0 && R == 0 && C == 0 && K == 0) {
            break;
        }

        vector<vector<int>> arr(R, vector<int>(C));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> arr[i][j];
            }
        }

        while (K--) {
            vector<vector<int>> res = arr;

            for (int x = 0; x < R; x++) {
                for (int y = 0; y < C; y++) {
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
                            (arr[nx][ny] + 1) % N == arr[x][y]) {
                            res[x][y] = arr[nx][ny];
                            break;
                        }
                    }
                }
            }

            arr = res;
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (j > 0) cout << " ";
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }
}