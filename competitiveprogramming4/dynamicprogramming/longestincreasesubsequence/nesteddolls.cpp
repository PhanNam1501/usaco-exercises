#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
            cin >> arr[i].second;
        }

        sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        vector<int> A(N);
        for (int i = 0; i < N; i++) A[i] = arr[i].second;
        
        vector<int> L(N);
        int k = 0; 
        
        for (int i = 0; i < N; i++) {
            int pos = upper_bound(L.begin(), L.begin() + k, A[i], greater<int>()) - L.begin();
            
            L[pos] = A[i];
            
            if (k == pos) {
                k = pos + 1;
            }
        }

        cout << k << "\n";
    }
}