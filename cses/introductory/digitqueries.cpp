#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n; 
        cin >> n;

        long long len = 1;
        long long cnt = 9;
        long long start = 1;

        while (n > cnt * len) {
            n -= len * cnt;
            len++;
            start *= 10;
            cnt *= 10;
        }

        long long number = start + (n-1)/len;

        long long digit = (n-1)%len;

        string s = to_string(number);
        
        cout << s[digit] << "\n";

    }
}