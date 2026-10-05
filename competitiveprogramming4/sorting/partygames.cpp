#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<string> arr(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            arr[i] = s;
        }

        string res = "";
        sort(arr.begin(), arr.end());
        string l = arr[arr.size()/2-1];
        string r = arr[arr.size()/2];
        int N = max(l.size(), r.size());
        for (int i = 0; i < l.size(); i++) {
            if (i == l.size()-1) {
                string s(1, l[i]);
                res += s;
                break;
            } else if (i == r.size()-1) {
                if (int(r[i] - l[i]) == 1) {
                    res += string(1, l[i]);
                    for (int j = i+1; j < N; j++) {
                        if (j == N-1) {
                            res += string(1, l[j]);
                            break;
                        } else if (l[j] < 'Z') {
                            res += string(1, l[j]+1);
                            break;
                        } else {
                            res += string(1, l[j]);
                        }
                    }
                    break;
                } else {
                    string s(1, l[i]+1);
                    res += s;
                    break;
                }
            }

            if (int(r[i] - l[i]) > 1) {
                string s(1, l[i] + 1);
                res += s;
                break;
            } else if (int(r[i] - l[i]) == 1) {
                string s(1, r[i]);
                res += s;
                break;
            }
            string s(1, l[i]);
            res += s;
        }
        cout << res << "\n";
    }
}