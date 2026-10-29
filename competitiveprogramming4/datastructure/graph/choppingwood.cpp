#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_map<int, int> mp;
    vector<int> cnt(n+1);
    for (int i = 0; i < n; i++) mp[arr[i]]++;
    for (int i = 1; i <= n+1; i++) {
        if (mp[i] == 0) {
            minHeap.push(i);
        }
    }
    vector<int> out;
    for (int i = 0; i < n; i++) {
        if (minHeap.top() == n+1) {
            cout << "Error\n";
            return 0;
        }
        out.push_back(minHeap.top());
        minHeap.pop();
        mp[arr[i]]--;
        if (mp[arr[i]] == 0) minHeap.push(arr[i]);
    }
    while (minHeap.size() != 1) {
        out.push_back(minHeap.top());
        minHeap.pop();
    }
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << "\n";
    }
}