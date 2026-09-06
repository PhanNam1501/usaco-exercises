#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n; 
    cin >> n;
    long long summ = n * (n+1) / 2;
    if (summ % 2 == 1) cout << "NO";
    else {
        cout << "YES" << "\n";
        if (n % 2 == 0) {
            cout << n / 2 << "\n";
            long long cnt = 1;
            for (int i = 1; i <= n/4; i++) {
                cout << cnt << " ";
                cout << n+1 - cnt << " ";
                cnt++;
            }
            cout << "\n";
            cout << n / 2 << "\n";
            for (int i = 1; i <= n/4; i++) {
                cout << cnt << " ";
                cout << n+1 - cnt << " ";
                cnt++;
            }
            cout << "\n";
        } else {
            cout << n / 2 << "\n";
            long long cnt = 1;
            for (int i = 1; i <= n/4; i++) {
                cout << cnt << " ";
                cout << n - cnt << " ";
                cnt++;
            }
            cout << n;
            cout << "\n";
            cout << n / 2 + 1 << "\n";
            for (int i = 1; i <= (n/2+1)/2; i++) {
                cout << cnt << " ";
                cout << n - cnt << " ";
                cnt++;
            }
        }
    }
}