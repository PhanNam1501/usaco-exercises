#include <bits/stdc++.h>
using namespace std;

void swaprow(vector<vector<int>>& arr, int a, int b) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        swap(arr[a][i], arr[b][i]);
    }
}

void swapcol(vector<vector<int>>& arr, int a, int b) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        swap(arr[i][a], arr[i][b]);
    }
}

vector<vector<int>> transpose(const vector<vector<int>>& arr) {
    int n = arr.size();

    vector<vector<int>> res(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[j][i] = arr[i][j];
        }
    }

    return res;
}

void inc(vector<vector<int>>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = (arr[i][j] + 1) % 10;
        }
    }
}

void dec(vector<vector<int>>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = (arr[i][j] + 9) % 10;
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;

        vector<vector<int>> arr(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < n; j++) {
                arr[i][j] = s[j] - '0';
            }
        }

        int m;
        cin >> m;

        while (m--) {
            string op;
            cin >> op;

            if (op == "row") {
                int a, b;
                cin >> a >> b;

                swaprow(arr, a - 1, b - 1);

            } else if (op == "col") {
                int a, b;
                cin >> a >> b;

                swapcol(arr, a - 1, b - 1);

            } else if (op == "inc") {
                inc(arr);

            } else if (op == "dec") {
                dec(arr);

            } else if (op == "transpose") {
                arr = transpose(arr);
            }
        }

        cout << "Case #" << tc << '\n';

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j];
            }
            cout << '\n';
        }

        cout << '\n';
    }

    return 0;
}