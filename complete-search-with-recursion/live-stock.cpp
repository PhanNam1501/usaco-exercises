#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> cows = {
        "Beatrice",
        "Belinda",
        "Bella",
        "Bessie",
        "Betsy",
        "Blue",
        "Buttercup",
        "Sue"
    };

    int N;
    cin >> N;
    cin.ignore();
    vector<vector<string>> besides(N);
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string a, b, c, d, e, f;
        ss >> a >> b >> c >> d >> e >> f;
        besides[i] = {a, f};
    }

    do {
        int check = true;
        for (int i = 0; i < 8; i++) {
            string name = cows[i];
            for (int j = 0; j < N; j++) {
                int leftcheck = false;
                int rightcheck = false;
                string beside = "";
                if (name == besides[j][0] || name == besides[j][1]) {
                    if (name == besides[j][0]) {
                        beside = besides[j][1];
                    } else {
                        beside = besides[j][0];
                    }
                }
                if (beside != "") {
                    if (i > 0) {
                        if (beside == cows[i-1]) {
                            leftcheck = true;
                        }
                    }

                    if (i < 7) {
                        if (beside == cows[i+1]) {
                            rightcheck = true;
                        }
                    }

                    if (leftcheck || rightcheck) {
                        continue;
                    } else {
                        check = false;
                        break;
                    }
                }

            }
        } 
        if (check) {
            for (auto x : cows) {
                cout << x << "\n";
            }
            return 0;
        }
    } while (next_permutation(cows.begin(), cows.end()));
}