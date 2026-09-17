#include <bits/stdc++.h>
using namespace std;

string shuffle(int n, string word, string &s) {
    string res = "";

    if (n % 2 == 0) {
        string after = s.substr(n / 2);

        for (int i = 0; i < n / 2; i++) {
            res += s[i];
            res += after[i];
        }

    } else {
        if (word == "in") {
            // ABCDE
            // AB | CDE
            // C A D B E

            string after = s.substr(n / 2);

            for (int i = 0; i < n / 2; i++) {
                res += after[i];
                res += s[i];
            }

            res += after[n / 2];

        } else {
            // ABCDE
            // ABC | DE
            // A D B E C

            string after = s.substr(n / 2 + 1);

            for (int i = 0; i < n / 2; i++) {
                res += s[i];
                res += after[i];
            }

            res += s[n / 2];
        }
    }

    return res;
}

int main() {
    int n;
    string word;

    cin >> n >> word;

    int res = 0;

    string s = "";

    for (int i = 0; i < n; i++) {
        s += char('A' + i);
    }

    string original = s;

    while (true) {
        s = shuffle(n, word, s);
        res++;

        if (s == original) {
            break;
        }
    }

    cout << res << "\n";
}