#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    int l = 0;
    int r = N-1;
    for (int i = 0; i < N; i++) {
        if (a[i] == b[i]) l++;
        else {
            break;
        }
    };


    if (l == N) {
        cout << "Yes";
        return 0;
    }

    for (int i = N-1; i >= 0; i--) {
        if (a[i] == b[i]) r--;
        else {
            break;
        }
    }

    if (l == r) {
        cout << "No";
        return 0;
    }

    
    if (b[l] == a[l+1] && a[l] == b[r]) {
        bool check = true;
        for (int i = l+1; i <= r; i++) {
            if (a[i] != b[i-1]) {
                check = false;
            }
        }

        if (check == true) {
            cout << "Yes";
            return 0;
        }
    } 

    

    
    
    if (a[r] == b[l] && b[r] == a[r-1]) {
        bool check = true;
        for (int i = l; i < r; i++) {
            if (a[i] != b[i+1]) {
                check = false;
            }
        }
        if (check == true) {
            cout << "Yes";
            return 0;
        }
    } 

    cout << "No";
    
}