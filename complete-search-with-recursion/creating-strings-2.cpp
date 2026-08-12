#include <bits/stdc++.h>
using namespace std;

long long n;
string arr;
string res;
vector<string> ret;
int char_count[26];
void backtrack() {
    if(res.size() == n){
        ret.push_back(res);
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (char_count[i] > 0) {
            char_count[i]--;
            res.push_back('a'+i);
            backtrack();
            char_count[i]++;
            res.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    res = "";
    cin >> arr;
    n = arr.size();
    for (int i = 0; i < n; i++) {
        char_count[arr[i] - 'a']++;
    }
    backtrack();
    cout << ret.size() << "\n";
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << "\n";
    }
    return 0;
}