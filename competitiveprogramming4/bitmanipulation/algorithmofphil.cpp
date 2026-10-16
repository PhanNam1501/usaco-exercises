#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    int cases = 1;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        int l = 0;
        int r = 0;
        if (n % 2 == 0) {
            l = n/2-1;
            r = n/2;
        } else {
            l = n/2;
            r = n/2;
        }
        long long res = 0;
        int check = n;
        while(check > 0) {
            if (check % 2 == 1) {
                res <<= 1;
                if (l == r) {
                    if (s[l] == '1') {
                        res = (res + 1);
                    }
                    l--;
                    r++;
                } else if (n - r > l + 1) {
                    if (s[r] == '1') {
                        res = (res + 1);
                    }
                    r++;
                } else {
                    if (s[l] == '1') {
                        res = (res + 1);
                    }
                    l--;
                }
            } else {
                res <<= 1;
                if (s[l] == '1' && (s[r] == '0' || s[r] == '1')) {
                    res = (res + 1);
                    l--;
                } else if (s[l] == '0' && s[r] == '1') {
                    res = (res + 1);
                    r++;
                } else {
                    l--;
                }
            }
            res = (res % 1000000007) % 1000000007;
            check--;
        }

        cout << "Case #" << cases << ": " << res << "\n";
        cases++;
    }

    
    //1101010 // 2 + 8 + 32 + 64
}