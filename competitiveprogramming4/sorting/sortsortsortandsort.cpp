#include<bits/stdc++.h>
using namespace std;

struct result {
    int number;
    int value;
};


int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<result> res(N);
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            int t = 0;
            result r = {x, x%M};
            res[i] = r;
        } 
        cout << N << " " << M << "\n";
        if (N == 0 && M == 0) break;

        sort(res.begin(), res.end(), [](const result &a, const result &b) {
            if (a.value == b.value) {
                if (a.number % 2 == 0) {
                    if (b.number % 2 == 0) {
                        return a.number < b.number;
                    } else {
                        return false;
                    }
                } else {
                    if (b.number % 2 == 0) {
                        return true;
                    } else {
                        return a.number > b.number;
                    }
                }
            }
            return a.value < b.value;
        });

        for (int i = 0; i < N; i++) {
            cout << res[i].number << "\n";
        }
    }

}