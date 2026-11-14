#include<bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> A;

bool first = false;

void print_lis(int i) {
    if (p[i] == -1) {
        printf(" %d", A[i]);
        return;
    }
    print_lis(p[i]);
    printf(" %d", A[i]);
}

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;
        A.resize(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        p.assign(N, -1);
        int k = 0;
        int last_id = 0;
        vector<int> L(N);
        vector<int> L_id(N);
        for (int i = 0; i < N; i++) {
            int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
            L[pos] = A[i];
            L_id[pos] = i;
            p[i] = pos ? L_id[pos-1] : -1;
            if (k == pos) {
                k = pos + 1;
                last_id = i;
            }
        }
        cout << k;
        print_lis(last_id);
        cout << "\n";
        p = vector<int>{};
        A = vector<int>{};
        first = false;
    }
}