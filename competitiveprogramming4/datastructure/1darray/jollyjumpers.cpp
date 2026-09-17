#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        vector<int> check(n, 0);
        
        for (int i = 0; i < n-1; i++) {
            int t = abs(arr[i+1] - arr[i]);
            if (t >= 1 && t < n) {
                check[t] = 1;
            }
        }
        bool invalid = false;
        for (int i = 1; i < n; i++) {
            if (check[i] == 0) {
                invalid = true;
                cout << "Not jolly\n";
                break;
            } 
        }

        if (!invalid) cout << "Jolly\n";
    }
}