#include<bits/stdc++.h>
using namespace std;

int n, l, r;
int res = 0;
int res2 = 0;
int maxx1 = 0;
int maxx2 = 0;
int count1 = 0;
int count2 = 0;

void backtrack2(int c, int n2, vector<bool>& visited) {
    if (c == n2) {
        if (count2 == r - 1) res2++; 
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (i > maxx2) count2++;
            int mockmaxx2 = maxx2;
            maxx2 = max(maxx2, i);
            visited[i] = true;
            if (count2 <= r-1) {
                backtrack2(c+1, n2, visited);
            } 
            if (i > mockmaxx2) count2--;
            visited[i] = false;
            maxx2 = mockmaxx2;
        }

    }
}

void backtrack1(int c, int n1, int n2, vector<bool>& visited) {
    if (c == n1) {
        if (count1 == l - 1) {       
            backtrack2(0, n2, visited);
            res += res2;
            res2 = 0;
            maxx2 = 0;
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (i > maxx1) count1++;
            int mockmaxx1 = maxx1;
            maxx1 = max(maxx1, i);
            visited[i] = true;
            if (count1 <= l-1) {
                backtrack1(c+1, n1, n2, visited);
            } 
            if (i > mockmaxx1) count1--;
            visited[i] = false;
            maxx1 = mockmaxx1;
        }

    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> l >> r;

        vector<bool> visited(n+1, false);
        int pos1 = l;
        int pos2 = n - r + 1;
        visited[n] = true;

        for (int pos = pos1; pos <= pos2; pos++) {
            backtrack1(0, pos-1, n-pos, visited);
        }
        cout << res << "\n";
        res = 0;
        res2 = 0;
        maxx1 = 0;
        maxx2 = 0;
        count1 = 0;
        count2 = 0;
    }
}