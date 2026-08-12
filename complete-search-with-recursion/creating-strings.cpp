#include <bits/stdc++.h>
using namespace std;

long long n;
string arr;
map<int, bool> visited;
string res;
int cnt;
vector<string> ret;

void backtrack() {
    if(res.size() == n){
        ret.push_back(res);
        cnt++;
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if(visited[i]) continue;

        if(i>0 && arr[i]==arr[i-1] && !visited[i-1]) continue;

        visited[i] = true;
        res.push_back(arr[i]);
        backtrack();
        res.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cnt = 0;
    res = "";
    cin >> arr;
    n = arr.size();
    sort(arr.begin(), arr.end());
    backtrack();
    cout << cnt << "\n";
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << "\n";
    }
    return 0;
}