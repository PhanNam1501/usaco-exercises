#include<bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> A;

void print_LIS(int i) {
    if (p[i] == -1) { printf("%d", A[i]); return; }// base case
    print_LIS(p[i]); // backtrack
    printf(" %d", A[i]);
}

int main() {
    int n;
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    int k = 0;
    int lis_end = 0;
    p.assign(n, -1);
    vector<int> L(n);
    vector<int> L_id(n);

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i];
        L_id[pos] = i;

        p[i] = pos ? L_id[pos-1] : -1;
        if (k == pos) {
            k++;
            lis_end = i;
        }
    }

    printf("Final LIS is of length %d: ", k);
    print_LIS(lis_end); printf("\n");
}