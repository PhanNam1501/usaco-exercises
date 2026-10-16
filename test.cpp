#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> res = vector<int>(arr.begin() + 1, arr.begin() + 5);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }
}