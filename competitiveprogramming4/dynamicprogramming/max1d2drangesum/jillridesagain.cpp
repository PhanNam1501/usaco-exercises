#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    int route = 1;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n-1);
        for (int i = 0; i < n-1; i++) {
            cin >> arr[i];
        }
        int l = 1;
        int r = 2;
        int ans = 0;
        int summ = 0;
        int lval = 0;
        int rval = 0;
        unordered_map<int, int> maxRoad;
        for (int i = 0; i < n-1; i++) {
            summ += arr[i];
            if (summ >= ans) {
                if ((summ == ans && r - l > maxRoad[summ]) || summ > ans) {
                    lval = l;
                    rval = r;
                }
                maxRoad[summ] = r - l;
                ans = summ;
            } 
            if (summ < 0) {
                summ = 0;
                l = i+2;
                r = i+3;
            } else {
                r++;
            }
        }
        if (lval == 0 && rval == 0) {
            cout << "Route " << route << " has no nice parts\n";
        } else {
            cout << "The nicest part of route " << route << " is between stops " << lval << " and " << rval << "\n";
        }
        route++;
    }
}