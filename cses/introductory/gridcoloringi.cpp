#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i =  0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int prev = j-1;
            int upper = i-1;
            for (int k = 0; k < 4; k++) {
                char x = char('A' + k);
                if (prev != -1 && x == arr[i][prev]) {
                    continue;
                }

                if (upper != -1 && x == arr[upper][j]) {
                    continue;
                }

                if (x == arr[i][j]) {
                    continue;
                }

                arr[i][j] = x;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}