#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> freq1(101, 0);
    vector<int> freq2(101, 0);

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        freq1[a]++;
        freq2[b]++;

        vector<int> tempA = freq1;
        vector<int> tempB = freq2;

        int l = 100; 
        int r = 1;   
        int max_sum = 0;

        while (l >= 1 && r <= 100) {
            while (l >= 1 && tempA[l] == 0) l--;
            while (r <= 100 && tempB[r] == 0) r++;

            if (l >= 1 && r <= 100) {
                max_sum = max(max_sum, l + r);

                int take = min(tempA[l], tempB[r]);
                tempA[l] -= take;
                tempB[r] -= take;
            }
        }

        cout << max_sum << "\n";
    }

    return 0;
}