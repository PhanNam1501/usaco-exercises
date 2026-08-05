#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int result = 0;
    int res = 1;
    for (int i = 0; i < N; i++) {
        int l = i-1;
        int r = i+1;
        int boom = 1;
        int mockleft = i;
        while (true) {
            bool check = false;
            int lcheck = l;
            while (l >= 0 && arr[l] >= arr[mockleft] - boom) {
                l--;
                res += 1;
                check = true;
            }

            if (lcheck == l) {
                break;
            }

            if (check) {
                boom += 1;
                mockleft = l+1;
            }
        }
        

        boom = 1;
        int mockright = i;
        while(true) {
            bool check = false;
            int rcheck = r;
            while (r < N && arr[r] <= arr[mockright] + boom) {
                r++;
                res += 1;
                check = true;
            }

            if (rcheck == r) {
                break;
            }

            if (check) {
                boom += 1;
                mockright = r-1;
            }
        }
        
        result = max(res, result);
        res = 1;
    }

    cout << result << "\n";
}