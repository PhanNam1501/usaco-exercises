#include <bits/stdc++.h>
using namespace std;

int main() {
    int S, B;

    while (cin >> S >> B) {
        if (S == 0 && B == 0)
            break;

        vector<int> pre(S + 2);
        vector<int> suf(S + 2);

        for (int i = 1; i <= S; i++) {
            pre[i] = i - 1;
            suf[i] = i + 1;
        }

        while (B--) {
            int L, R;
            cin >> L >> R;

            int left = pre[L];
            int right = suf[R];

            if (left != 0)
                suf[left] = right;

            if (right != S + 1)
                pre[right] = left;

            if (left == 0)
                cout << "* ";
            else
                cout << left << " ";

            if (right == S + 1)
                cout << "*\n";
            else
                cout << right << "\n";
        }

        cout << "-\n";
    }
}