#include<bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;


    int prevPrev = 1; // dp[i-2]
    int prev = 1; //dp[i-1]
    int curr = 0;
    for (int i = 2; i <= n; i++) {
        curr = prev + prevPrev;
        prevPrev = prev;
        prev = curr;
    }

    cout << curr << '\n';
}