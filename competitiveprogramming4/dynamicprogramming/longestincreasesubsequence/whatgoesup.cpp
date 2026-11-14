#include<bits/stdc++.h>
using namespace std;

vector<int> A;
vector<int> p;

void print_LIS(int i) {
    if (i == -1) return;
    print_LIS(p[i]);
    cout << A[i] << "\n";
}

int main() {
    int x;
    while (cin >> x) {
        A.push_back(x);
    }

    int n = A.size();
    p.assign(n, -1);
    int k = 0;
    int lis_end = 0;
    vector<int> L(n);
    vector<int> L_id(n);

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();

        L[pos] = A[i];
        L_id[pos] = i;

        p[i] = pos ? L_id[pos-1] : -1;
        if (pos == k) {
            k = pos + 1;
            lis_end = i;
        }
    }

    cout << k << "\n";
    cout << "-\n";
    print_LIS(lis_end);
}