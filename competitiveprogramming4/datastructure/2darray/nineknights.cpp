#include<bits/stdc++.h>
using namespace std;

vector<int> dx{1, -1, -2, -2, -1, 2, 2, 1};
vector<int> dy{-2, -2, -1, 1, 2, -1, 1, 2};

int main() {
    vector<string> arr(5);
    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        arr[i] = s;
    }
    int cnt = 0;
    bool invalid = false;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i][j] == 'k') {
                cnt++;
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && arr[nx][ny] == 'k') {
                        cout << "invalid" << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    if (cnt != 9) {
        cout << "invalid" << "\n";
    } else {
        cout << "valid" << "\n";
    }
}