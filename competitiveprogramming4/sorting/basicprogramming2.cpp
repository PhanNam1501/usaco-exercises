#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, t;
    if (!(cin >> N >> t)) return 0;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    switch (t) {
        case 1: {
            unordered_map<int, bool> mp;
            for (int i = 0; i < N; i++) {
                if (mp.count(7777 - arr[i])) {
                    cout << "Yes\n";
                    return 0;
                }
                mp[arr[i]] = true; 
            }
            cout << "No\n";
            break;
        }
        
        case 2: {
            unordered_map<int, int> cnt;
            for (int i = 0; i < N; i++) {
                if (cnt[arr[i]] >= 1) {
                    cout << "Contains duplicate\n";
                    return 0;
                }
                cnt[arr[i]]++;
            }
            cout << "Unique\n";
            break;
        }
        
        case 3: {
            unordered_map<int, int> cnt;
            for (int i = 0; i < N; i++) {
                cnt[arr[i]]++;
                if (cnt[arr[i]] > N / 2) {
                    cout << arr[i] << "\n";
                    return 0;
                }
            }
            cout << -1 << "\n";
            break;
        }
        
        case 4: {
            sort(arr.begin(), arr.end()); 
            if (N % 2 == 1) {
                cout << arr[N / 2] << "\n";
            } else {
                cout << arr[N / 2 - 1] << " " << arr[N / 2] << "\n";
            }
            break;
        }
        
        case 5: {
            sort(arr.begin(), arr.end());
            int l = 0;
            int r = N - 1;
            while (l < N && arr[l] < 100) {
                l++;
            }
            while (r >= 0 && arr[r] > 999) {
                r--;
            }
            for (int i = l; i <= r; i++) {
                if (i == r) {
                    cout << arr[i] << "\n";
                } else {
                    cout << arr[i] << " ";
                }
            }
            break;
        }
    }
    
    return 0;
}