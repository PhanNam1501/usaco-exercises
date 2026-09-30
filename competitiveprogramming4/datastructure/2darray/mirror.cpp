#include <bits/stdc++.h>
using namespace std;

// rotate left
vector<string> rot(vector<string> &arr)
{
    int n = arr.size();
    vector<string> res(n, string(n, ' '));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[j][n - i - 1] = arr[i][j];
        }
    }
    return res;
}

// fuck gpt
vector<string> vertical(vector<string> &arr)
{
    int n = arr.size();
    vector<string> res(n, string(n, ' '));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[n - 1 - i][j] = arr[i][j];
        }
    }

    return res;
}

int main()
{
    int n;
    int pattern = 0;
    while (cin >> n)
    {
        pattern++;

        vector<string> arr(n);
        vector<string> samp(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i] >> samp[i];
        }

        if (arr == samp)
        {
            cout << "Pattern " << pattern << " was preserved.\n";
            continue;
        }

        bool check = false;
        vector<string> mock = arr;
        for (int i = 0; i < 3; i++)
        {
            mock = rot(mock);
            if (mock == samp)
            {
                if (i == 0)
                {
                    cout << "Pattern " << pattern << " was rotated 90 degrees.\n";
                }
                else if (i == 1)
                {
                    cout << "Pattern " << pattern << " was rotated 180 degrees.\n";
                }
                else
                {
                    cout << "Pattern " << pattern << " was rotated 270 degrees.\n";
                }
                check = true;
                break;
            }
        }

        if (check)
            continue;
        mock = vertical(arr);
        if (mock == samp)
        {
            cout << "Pattern " << pattern << " was reflected vertically.\n";
            continue;
        }
        check = false;
        for (int i = 0; i < 3; i++)
        {
            mock = rot(mock);
            if (mock == samp)
            {
                if (i == 0)
                {
                    cout << "Pattern " << pattern << " was reflected vertically and rotated 90 degrees.\n";
                }
                else if (i == 1)
                {
                    cout << "Pattern " << pattern << " was reflected vertically and rotated 180 degrees.\n";
                }
                else
                {
                    cout << "Pattern " << pattern << " was reflected vertically and rotated 270 degrees.\n";
                }
                check = true;
                break;
            }
        }
        if (check)
            continue;

        cout << "Pattern " << pattern << " was improperly transformed.\n";
    }
}

// This question is an nightmare, the logic code is easy but ...