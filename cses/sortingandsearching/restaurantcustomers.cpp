#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    int res = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && arr[i].first >= pq.top()) {
            pq.pop();
        }
        pq.push(arr[i].second);
        res = max(res, int(pq.size()));
    }
    cout << res << "\n";
}