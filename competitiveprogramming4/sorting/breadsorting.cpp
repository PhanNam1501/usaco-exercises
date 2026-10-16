#include<bits/stdc++.h>
using namespace std;

long long merge(vector<int> &arr, int l, int m, int r) {
    long long inv_count = 0;
    vector<int> temp{}; // fuck
    int left = l;
    int right = m+1;
    while (left <= m && right <= r) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
            inv_count += m - left + 1;
        }
    }

    while (left <= m) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= r) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = l; i <= r; i++) {
        arr[i] = temp[i-l];
    }

    return inv_count;
}

long long mergeSortAndCount(vector<int> &arr, int l, int r) {
    long long inv_count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        inv_count += mergeSortAndCount(arr, l, m);
        inv_count += mergeSortAndCount(arr, m+1, r);
        inv_count += merge(arr, l, m, r);
    }
    return inv_count;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int t1 = mergeSortAndCount(a, 0, n-1) % 2;
    int t2 = mergeSortAndCount(b, 0, n-1) % 2;
    if (t1 == t2) {
        cout << "Possible" << "\n";
    } else {
        cout << "Impossible" << "\n";
    }


}