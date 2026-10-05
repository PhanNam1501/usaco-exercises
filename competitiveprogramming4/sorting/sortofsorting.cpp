#include<bits/stdc++.h>
using namespace std;

struct Position {
    string name;
    int pos;
};

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<Position> arr(n);
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            Position pos = {name, i};
            arr[i] = pos;
        }

        sort(arr.begin(), arr.end(), [](const Position& a, const Position& b) {
            for (int i = 0; i < 2; i++) {
                if (a.name[i] != b.name[i]) {
                    return a.name[i] < b.name[i];
                }
            }

            return a.pos < b.pos;
        });

        for (int i = 0; i < n; i++) {
            cout << arr[i].name << "\n";
        }

        cout << "\n";
    }
}