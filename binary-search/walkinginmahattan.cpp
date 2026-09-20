#include <bits/stdc++.h>
using namespace std;

int upper(vector<long long> &arr, long long target)
{
    int l = 0;
    int r = arr.size();

    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] <= target)
            l = m + 1;
        else
            r = m;
    }

    return l;
}

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<long long> roadsV;
    vector<long long> roadsH;

    unordered_set<long long> setV;
    unordered_set<long long> setH;

    for (int i = 0; i < N; i++)
    {
        char direction;
        long long c;

        cin >> direction >> c;

        if (direction == 'V')
        {
            roadsV.push_back(c);
            setV.insert(c);
        }
        else
        {
            roadsH.push_back(c);
            setH.insert(c);
        }
    }

    sort(roadsV.begin(), roadsV.end());
    sort(roadsH.begin(), roadsH.end());

    while (Q--)
    {
        long long x, y, d;
        cin >> x >> y >> d;

        long long remaining = d;
        long long elapsed = 0;

        bool isNorth = false;

        while (remaining > 0)
        {
            bool hasV = setV.count(x);
            bool hasH = setH.count(y);

            if (hasV && hasH)
            {
                if (elapsed % 2 == 0)
                    isNorth = true;
                else
                    isNorth = false;
            }
            else if (hasV)
            {
                isNorth = true;
            }
            else if (hasH)
            {
                isNorth = false;
            }

            if (isNorth)
            {
                int t = upper(roadsH, y);

                if (t == roadsH.size())
                {
                    y += remaining;
                    elapsed += remaining;
                    remaining = 0;
                }
                else
                {
                    long long dist = roadsH[t] - y;

                    if (dist >= remaining)
                    {
                        y += remaining;
                        elapsed += remaining;
                        remaining = 0;
                    }
                    else
                    {
                        y = roadsH[t];
                        remaining -= dist;
                        elapsed += dist;
                    }
                }
            }
            else
            {
                int t = upper(roadsV, x);

                if (t == roadsV.size())
                {
                    x += remaining;
                    elapsed += remaining;
                    remaining = 0;
                }
                else
                {
                    long long dist = roadsV[t] - x;

                    if (dist >= remaining)
                    {
                        x += remaining;
                        elapsed += remaining;
                        remaining = 0;
                    }
                    else
                    {
                        x = roadsV[t];
                        remaining -= dist;
                        elapsed += dist;
                    }
                }
            }
        }

        cout << x << " " << y << "\n";
    }
}