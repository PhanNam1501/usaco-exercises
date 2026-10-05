#include<bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    while (cin >> r >> c) {
        if (r == 0 && c == 0) break;
        vector<string> arr(r);
        for (int i = 0; i < r; i++) {
            cin >> arr[i];
        }

        vector<string> res(c);
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                res[j] += arr[i][j];
            }
        }

        sort(res.begin(), res.end(), [](const string& a, const string& b) {
            int n = min(a.size(), b.size());

            for (int i = 0; i < n; i++) {
                if (tolower(a[i]) != tolower(b[i]))
                    return tolower(a[i]) < tolower(b[i]);
            }

            return a.size() < b.size();
        });
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << res[j][i];
            }
            cout << "\n";
        }

        

    }
}