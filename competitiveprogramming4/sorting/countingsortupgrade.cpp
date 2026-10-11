#include<bits/stdc++.h>
using namespace std;

long long merge(string &arr, int left, int mid, int right) {
    string temp = "";
    int i = legt;
    int j = mid+1;
    long long inv_count = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp += arr[j++];
        } else {
            temp += arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp += arr[i++];
    }

    while (j <= right) {
        temp += arr[j++];
    }

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }

    return inv_count;
}

long long mergeSortAndCount(string &arr, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inv_count += mergeSortAndCount(arr, left, mid);
        inv_count += mergeSortAndCount(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}

struct Result {
    string original_dna;
    long long cnt;
    int index;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    if (!(cin >> M)) return 0;

    while (M--) {
        int n, m;
        cin >> n >> m;

        vector<Result> res(m);
        for (int i = 0; i < m; i++) {
            string dna;
            cin >> dna;
            string temp_dna = dna;
            long long inversions = mergeSortAndCount(temp_dna, 0, n - 1);
            res[i] = {dna, inversions, i};
        }

        sort(res.begin(), res.end(), [](const Result &a, const Result &b) {
            if (a.cnt == b.cnt) {
                return a.index < b.index;
            }
            return a.cnt < b.cnt;
        });

        for (int i = 0; i < m; i++) {
            cout << res[i].original_dna << "\n";
        }

        if (M > 0) {
            cout << "\n";
        }
    }

    return 0;
}
