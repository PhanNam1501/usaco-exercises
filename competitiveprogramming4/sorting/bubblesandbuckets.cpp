#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int> &arr, int left, int mid, int right) {
    int l = left;
    int r = mid + 1;

    vector<int> temp;
    long long inv_count = 0;
    while (l <= mid && r <= right) {
        if (arr[l] <= arr[r]) {
            temp.push_back(arr[l]);
            l++;
        } else {
            temp.push_back(arr[r]);
            r++;
            inv_count += (mid - l + 1);
        }
    }

    while (l <= mid) {
        temp.push_back(arr[l]);
        l++;
    }

    while (r <= right) {
        temp.push_back(arr[r]);
        r++;
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }

    return inv_count;
}

long long mergeSortAndCount(vector<int> &arr, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inv_count += mergeSortAndCount(arr, left, mid);
        inv_count += mergeSortAndCount(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }

    return inv_count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long inv_count = mergeSortAndCount(arr, 0, n - 1);

        if (inv_count % 2 == 1) {
            cout << "Marcelo\n";
        } else {
            cout << "Carlos\n";
        }
    }
    return 0;
}
