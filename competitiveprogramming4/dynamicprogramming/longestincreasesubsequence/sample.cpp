#include<bits/stdc++.h>
using namespace std;

int memo[10005];
vector<int> A;

int LIS(int i) {
    if (i == 0) return 1;
    int &ans = memo[i];
    if (ans != -1) return memo[i];

    ans = 1;
    for (int j = 0; j < i; j++) {
        if (A[j] < A[i]) ans = max(ans, LIS(j));
    }
    memo[i] = ans;
    return ans;
}

int main() {
    memset(memo, -1, sizeof(memo));
    int n;
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    cout << LIS(n-1);
}