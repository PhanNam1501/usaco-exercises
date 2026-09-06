#include<bits/stdc++.h>
using namespace std;

int bsearch(vector<int> &arr, int x) {
    int l = 0;
    int r = arr.size();
    while (l < r) {
        int m = l + (r - l)/2;
        if (arr[m] > x) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());


    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        queries[i] = pair<int, int>{x, y};
    }

    for (int i = 0; i < Q; i++) {
        cout << bsearch(arr, queries[i].second) - bsearch(arr, queries[i].first-1) << "\n";
    }

    

}