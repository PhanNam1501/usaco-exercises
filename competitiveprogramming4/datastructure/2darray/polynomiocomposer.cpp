#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;

        vector<string> large(n);
        vector<string> small(m);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> large[i];
            for (int j = 0; j < n; j++)
            {
                if (large[i][j] == '*')
                    cnt++;
            }
        }

        for (int i = 0; i < m; i++)
        {
            cin >> small[i];
        }

        vector<pair<int, int>> pos;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (small[i][j] == '*')
                {
                    pos.push_back(pair<int, int>{i, j});
                }
            }
        }

        if (cnt != pos.size() * 2)
        {
            cout << 0 << "\n";
        }
        else
        {
            bool find = false;  
            // * *
            // . *
            for (int i = -m; i < n; i++)
            { // 10
                for (int j = -m; j < n; j++)
                { // 10
                    vector<vector<bool>> visited(n, vector<bool>(n));
                    bool check = true;
                    for (auto &k : pos)
                    {
                        int nx = i + k.first;
                        int ny = j + k.second;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && large[nx][ny] == '*')
                        {
                            visited[nx][ny] = true;
                        }
                        else
                        {
                            check = false;
                            break;
                        }
                    } // 10

                    if (check)
                    {
                        for (int ii = -m; ii < n; ii++)
                        { // 10
                            for (int jj = -m; jj < n; jj++)
                            { // 10
                                bool valid = true;
                                for (auto &k : pos)
                                {
                                    int nx = ii + k.first;
                                    int ny = jj + k.second;
                                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && large[nx][ny] == '*')
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        valid = false;
                                        break;
                                    }
                                } // 10

                                if (valid)
                                {
                                    find = true;
                                    break;
                                }
                            }
                            if (find)
                            {
                                break;
                            }
                        }
                    }
                    if (find)
                    {
                        break;
                    }
                }

                if (find)
                {
                    break;
                }
            }

            if (find)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
    }
}