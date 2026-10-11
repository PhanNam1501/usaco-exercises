#include<bits/stdc++.h>
using namespace std;

long long countt = 0;

string merge(string &arr) {
    int n = arr.size();
    if (n <= 2) {
        if (n == 2) {
            if (arr[0] > arr[1]) {
                countt++;
                swap(arr[0], arr[1]);
            }
        }
        return arr;
    }
    string left = arr.substr(0, n/2);
    string right = arr.substr(n/2);
    string merge1 = merge(left);
    string merge2 = merge(right);

    int l = 0;
    int r = 0;
    string res{};
    while (l < merge1.size() && r < merge2.size()) {
        if (merge1[l] > merge2[r]) {
            res += (merge2[r]);
            countt += merge1.size()-l;
            r++;
        } else {
            res += (merge1[l]);
            l++;
        }
    }

    while (l < merge1.size()) {
        res += (merge1[l]);
        l++;
    }

    while (r < merge2.size()) {
        res += (merge2[r]);
        r++;
    }

    return res;

}

struct Result {
    string dna;
    long long cnt;
    int original_index;
};

int main() {
    int M;
    cin >> M;
    string line;

    while (M--) {
        int m, n;
        cin >> n >> m;
        vector<string> arr(m);
        for (int i = 0; i < m; i++) {
            string dna;
            cin >> dna;
            arr[i] = dna;
        }


        vector<Result> res;

        for (int i = 0; i < m; i++) {
            string temp = arr[i];
            merge(temp);
            Result r = {arr[i], countt, i};
            res.push_back(r);
            countt = 0;
        }

        stable_sort(res.begin(), res.end(), [](const Result &a, const Result &b) {
            if (a.cnt == b.cnt) return a.original_index < b.original_index;
            return a.cnt < b.cnt;
        });

        for (int i = 0; i < m; i++) {
            cout << res[i].dna << "\n";
        }

        if (M > 0) cout << '\n';
    }
    return 0;
}













