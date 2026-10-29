#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; 
    
    for (int c = 1; c <= t; c++) {
        int n, k;
        cin >> n >> k; 
        
        int t = pow(2,n);

        if ((k+1) % t != 0) {
            cout << "CASE #" << c << ": OFF\n";
        } else {
            cout << "CASE #" << c << ": ON\n";
        }
    }
    return 0;
}