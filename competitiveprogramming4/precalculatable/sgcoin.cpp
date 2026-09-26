#include<bits/stdc++.h>
using namespace std;

long long getToken(long long previousHash, long long presentHash, string s) {
    long long v = previousHash;
    v = (v * 31 + s[0]) % 1000000007;
    while (presentHash < v * 7) {
        presentHash += 1000000007;
    }
    return presentHash - v * 7;
}

int main() {
    int n;
    cin >> n;
    string s1 = "a";
    string s2 = "b";
    long long token1 = 10000000;
    long long token2 = 20000000;
    cout << s1 << " " << getToken(n, token1, s1) << "\n";
    cout << s2 << " " << getToken(token1, token2, s2) << "\n";
}