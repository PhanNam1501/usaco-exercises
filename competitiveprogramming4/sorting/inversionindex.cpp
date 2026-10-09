#include<bits/stdc++.h>
using namespace std;

long long res = 0;

vector<int> merge(vector<int> &arr) {
    int n = arr.size();
    if (n <= 2) {
        if (n == 1) return arr;
        else {
            res += arr[0] > arr[1];
            if (arr[0] > arr[1]) {
                int t = arr[0];
                arr[0] = arr[1];
                arr[1] = t;
            }
            return arr;
        }
    }
    vector<int> left = vector<int>(arr.begin(), arr.begin() + n/2);
    vector<int> right = vector<int>(arr.begin() + n/2, arr.end());
    vector<int> m1 = merge(left);
    vector<int> m2 = merge(right);

    vector<int> m;
    int l = 0;
    int r = 0;

    // [3, 4, 5] [1, 2]

    while (l < m1.size() && r < m2.size()) {
        if (m1[l] <= m2[r]) {
            m.push_back(m1[l]);
            l++;
        } else {
            m.push_back(m2[r]);
            res += m1.size() - l;
            r++;
        }
    }

    while (l < m1.size()) {
        m.push_back(m1[l]);
        l++;
    }

    while (r < m2.size()) {
        m.push_back(m2[r]);
        r++;
    }

    return m;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> sortedArr = merge(arr);
    cout << res << "\n";
}