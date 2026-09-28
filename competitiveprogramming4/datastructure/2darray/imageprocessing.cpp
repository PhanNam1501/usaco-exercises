#include<bits/stdc++.h>
using namespace std;

int main() {
    int H, W, N, M;
    cin >> H >> W >> N >> M;

    vector<vector<int>> images(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> images[i][j];
        }
    }

    vector<vector<int>> kernels(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> kernels[i][j];
        }
    }

    vector<int> linelabels;
    for (int i = N-1; i >= 0; i--) {
        for (int j = M-1; j >= 0; j--) {
            linelabels.push_back(kernels[i][j]);
        }
    }

    int h = H - N + 1;
    int w = W - M + 1;
    vector<vector<int>> res(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int summ = 0;
            vector<int> lineimagesblur;
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < M; y++) {
                    lineimagesblur.push_back(images[x+i][y+j]);
                }
            }
            for (int k = 0; k < lineimagesblur.size(); k++) {
                summ += linelabels[k] * lineimagesblur[k];
            }
            res[i][j] = summ;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j == W-2) {
                cout << res[i][j] << "\n";
            } else {
                cout << res[i][j] << " ";
            }
        }
    }


}