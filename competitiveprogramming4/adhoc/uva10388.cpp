#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    if (!(cin >> t)) return 0;

    for (int tc = 0; tc < t; tc++)
    { 
        if (tc > 0) cout << "\n";

        string a, b;
        cin >> a >> b;

        string upa = "";
        string upb = "";
        int m = a.size();
        int n = b.size();
        int pa = 0;
        int pb = 0;
        int limit = 1000;

        while (true)
        {
            if (pa == m)
            {
                if (upa.empty()) {
                    cout << "John wins.\n";
                    break;
                }

                reverse(upa.begin(), upa.end());
                a = upa;
                upa = "";
                pa = 0;
                m = a.size();
            }

            if (pb == n)
            {
                if (upb.empty()) {
                    cout << "Jane wins.\n";
                    break;
                }

                reverse(upb.begin(), upb.end());
                b = upb;
                upb = "";
                pb = 0;
                n = b.size();
            }

            bool finished = false;
            while (pa < m && pb < n)
            {
                if (a[pa] != b[pb])
                {
                    upa = string(1, a[pa]) + upa;
                    upb = string(1, b[pb]) + upb;
                    pa++;
                    pb++;
                }
                else
                {
                    if (random() / 141 % 2 == 0)
                    {
                        upa = string(1, a[pa]) + upa;
                        upb = string(1, b[pb]) + upb;
                        upa = upb + upa;
                        upb = "";
                        pa++;
                        pb++;
                        cout << "Snap! for Jane: " << upa << "\n";
                    } 
                    else 
                    {
                        upa = string(1, a[pa]) + upa;
                        upb = string(1, b[pb]) + upb;
                        upb = upa + upb;
                        upa = "";
                        pa++;
                        pb++;
                        cout << "Snap! for John: " << upb << "\n";
                    }
                }
                
                limit--;

                if (upa == "" && pa == m) {
                    cout << "John wins.\n";
                    finished = true;
                    break;
                } 
                if (upb == "" && pb == n) {
                    cout << "Jane wins.\n";
                    finished = true;
                    break;
                }

                if (limit == 0)
                {
                    cout << "Keeps going and going ...\n";
                    finished = true;
                    break;
                }
            }

            if (finished) break;
        }
    }
    return 0;
}