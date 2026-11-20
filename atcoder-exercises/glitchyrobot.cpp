#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<long long> pre(N);
    
    pre[0] = arr[0];
    long long resMin = LONG_LONG_MAX;
    long long resMax = LONG_LONG_MIN;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            pre[i] = arr[i];
        } else {
            pre[i] = pre[i-1] + arr[i];
        }
        resMin = min(0LL, min(resMin, pre[i]));
        resMax = max(0LL, max(resMax, pre[i]));
    }

    vector<long long> lmin(N);
    vector<long long> lmax(N);
    long long curMin = LONG_LONG_MAX;
    long long curMax = LONG_LONG_MIN;
    for (int i = 1; i < N; i++) {
        curMin = min(0LL, min(curMin, pre[i-1]));
        curMax = max(0LL, max(curMax, pre[i-1]));
        lmin[i] = curMin;
        lmax[i] = curMax;
    }

    vector<long long> rmax(N);
    vector<long long> rmin(N);
    curMin = LONG_LONG_MAX;
    curMax = LONG_LONG_MIN;
    for (int i = N-2; i >= 0; i--) {
        curMin = min(curMin, pre[i+1]);
        curMax = max(curMax, pre[i+1]);
        rmin[i] = curMin;
        rmax[i] = curMax;
    }

    long long res = resMax-resMin+1;
    for (int i = 0; i < N; i++) {
        long long prep = i > 0 ? pre[i-1] : 0;
        long long t1 = i > 0 ? lmax[i] : LONG_LONG_MIN;
        long long t2 = i > 0 ? lmin[i] : LONG_LONG_MAX; 
        long long v1 = i < N-1 ? rmax[i] - 2*arr[i] : LONG_LONG_MIN;
        long long v2 = i < N-1 ? rmin[i] - 2*arr[i] : LONG_LONG_MAX;
        long long maxx = max(max(t1, v1), prep - arr[i]);
        long long minn = min(min(t2, v2), prep - arr[i]);
        res = max(res, maxx-minn+1);  
    }
    cout << res;
}
