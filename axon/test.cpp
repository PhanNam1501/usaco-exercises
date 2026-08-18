#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    // abababababab
    // abbaabaa
    int n = s.size();
    int cntA = 0;
    int cntB = 0;

    int res = 0;
    if (s[0] == 'a') cntA++;
    else cntB++;

    for (int i = 1; i < n; i++) {
        if (s[i] == 'a') cntA++;
        else cntB++;

        int mockA = cntA;
        int mockB = cntB;
        for(int j = 0; j < i; j++) {
            if (mockA == mockB) res++;
            if (s[j] == 'a') mockA--;
            else mockB--;
        }
    }

    cout << res << "\n";

}