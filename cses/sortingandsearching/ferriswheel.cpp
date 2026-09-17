#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    sort(p.begin(), p.end());
    int l = 0; int r = n - 1;

    int res = 0;
    while (l <= r) {
        if (l == r && p[l] <= x) 
        {
            res++;
            l++;
        } else {
            if (p[r] > x) r--;
            else if (p[r] <= x && p[l] + p[r] > x) {
                res++;
                r--;
            } else {
                res++;
                l++;
                r--;
            }
        } 
    }

    cout << res << "\n";
}