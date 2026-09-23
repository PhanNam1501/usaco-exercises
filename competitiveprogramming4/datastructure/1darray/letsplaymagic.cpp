#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {   
        if (n == 0) break;
        vector<pair<string, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            string x, y;
            cin >> x >> y;
            arr[i].first = x;
            arr[i].second = y.size();
        }

        int p = 0;
        vector<string> res(n);
        unordered_map<int, bool> mp;
        for (int i = 0; i < n; i++)
        {
            int c = arr[i].second;
            while (c != 0)
            {
                if (!mp[p])
                {   
                    c--;
                    if (c == 0) {
                        mp[p] = true;
                        res[p] = arr[i].first;
                    }
                    p++;
                }
                else
                {
                    p++;
                }

                if (p == n)
                {
                    p = 0;
                }
            }
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