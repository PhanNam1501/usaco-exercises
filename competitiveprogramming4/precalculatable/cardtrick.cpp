#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<queue<int>> qr(14);
    for (int x = 1; x <= 13; x++)
    {
        for (int i = x; i >= 1; i--)
        {
            qr[x].push(i);
            int c = i;
            while (c--)
            {
                int t = qr[x].front();
                qr[x].pop();
                qr[x].push(t);
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> res(n);
        queue<int> q = qr[n];
        for (int i = n-1; i >= 0; i--) {
            res[i] = q.front();
            q.pop();
        }

        for (int i = 0; i < n; i++) {
            if (i == n-1) {
                cout << res[i] << "\n";
            } else {
                cout << res[i] << " ";
            }
        }
    }
}