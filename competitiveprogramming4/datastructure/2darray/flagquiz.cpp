#include <bits/stdc++.h>
using namespace std;

int main()
{
    string question;
    getline(cin, question);

    int n;
    cin >> n;
    cin.ignore();

    vector<vector<string>> arr(n);
    vector<string> original(n);

    for (int i = 0; i < n; i++)
    {
        getline(cin, original[i]);

        string line = original[i];

        size_t start = 0;

        while (true)
        {
            size_t pos = line.find(", ", start);

            if (pos == string::npos)
            {
                arr[i].push_back(line.substr(start));
                break;
            }

            arr[i].push_back(line.substr(start, pos - start));

            start = pos + 2;
        }
    }

    vector<int> incongruity(n);

    for (int i = 0; i < n; i++)
    {
        int mx = 0;

        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            int changes = 0;

            for (int k = 0; k < arr[i].size(); k++)
            {
                if (arr[i][k] != arr[j][k])
                    changes++;
            }

            mx = max(mx, changes);
        }

        incongruity[i] = mx;
    }

    int best = *min_element(
        incongruity.begin(),
        incongruity.end()
    );

    for (int i = 0; i < n; i++)
    {
        if (incongruity[i] == best)
        {
            cout << original[i] << '\n';
        }
    }

    return 0;
}