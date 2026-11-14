#include<bits/stdc++.h>
using namespace std;

int main() {
    int K;
    cin >> K;
    vector<int> arr(K);
    for (int i = 0; i < K; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    if (arr[arr.size()-1] == 9) {
        cout << arr[0];
    } else {
        cout << -1;
    }
}