// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read from input file
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    // Parse input
    string str;
    cin >> str;

    map<char,bool> exist;
    map<char,bool> dup;
    map<char,int> start;
    // Solution here
    int res = 0;
    for (int i = 0; i < 52; i++) {
        if (exist[str[i]]) {
            for (int j = start[str[i]]; j < i; j++) {
                if (str[i] != str[j] && exist[str[i]] && !dup[str[j]]) {
                    res++;
                } 
                dup[str[i]] = true;
            }
        } else {
            exist[str[i]] = true;
            start[str[i]] = i;
        }
        
    }


    cout << res << "\n";

    return 0;
}
