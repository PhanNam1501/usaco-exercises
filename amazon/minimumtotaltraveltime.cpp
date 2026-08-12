#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> transitiionTime(m);
    vector<int> requestedHubs(n);

    for (int i = 0; i < m; i++) {
        cin >> transitiionTime[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> requestedHubs[i];
    }
    vector<int> pre(m);
    pre[0] = 0;

    for (int i = 1; i < m; i++) {
        pre[i] = transitiionTime[i-1] + pre[i-1];
    }

    for (int i = 0; i < m; i++) {
        cout << pre[i] << " ";
    }

    cout << "\n";

    int res = 0;
    int start = 0;
    for (int i = 1; i < n; i++) {
        int des = requestedHubs[i] - 1;

        int t1 = 0, t2 = 0;
        if (start > des) {
            int v = start;
            start = des;
            des = v;
        }
        t1 = pre[des] - pre[start];
        t2 = transitiionTime[m-1] + pre[start] + pre[m-1] - pre[des];
        cout << t1 << " " << t2 << "\n";
        res += min(t1, t2);
        start = des;
    }
    cout << res <<  "\n";
}

// time from i to j (->): pre[i] - pre[j] if j = 0: pre[j] = 0