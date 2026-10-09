#include<bits/stdc++.h>
using namespace std;

struct Dictionary {
    string name;
    string reversedName;
};

void process(vector<Dictionary> &res) {
    sort(res.begin(), res.end(), [](const Dictionary &a, const Dictionary &b) {
        int maxLen = max(a.name.size(), b.name.size());
        for (int i = 0; i < maxLen; i++) {
            if (i >= a.name.size() || i >= b.name.size()) break;
            if (a.reversedName[i] != b.reversedName[i]) {
                return a.reversedName[i] < b.reversedName[i];
            }
        }
        return a.name.size() < b.name.size(); 
    });
}

int main() {
    string line;
    vector<Dictionary> res;
    int maxLen = 0;
    while(getline(cin, line)) {
        if (line.empty()) {
            process(res);
            for (int i = 0; i < res.size(); i++) {
                for (int j = 0;  j < maxLen - res[i].name.size(); j++) {
                    cout << " ";
                }
                cout << res[i].name << "\n";
            }
            cout << "\n";
            res = vector<Dictionary>{};
            maxLen = 0;
            continue;
        }
        string reverseName =  line;
        reverse(reverseName.begin(), reverseName.end());
        Dictionary d = {line, reverseName};
        res.push_back(d);
        maxLen = max(maxLen, int(line.size()));
    }
    process(res);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0;  j < maxLen - res[i].name.size(); j++) {
            cout << " ";
        }
        cout << res[i].name << "\n";
    }
    res = vector<Dictionary>{};
    maxLen = 0;
}