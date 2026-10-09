#include<bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    vector<string> classes;
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string line;
        getline(cin, line);
        vector<Person> res(n);
        for (int i = 0; i < n; i++) {
            getline(cin, line);

            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }

            int p = line.find(':');
            string name = line.substr(0, p);
            string classname = line.substr(p+2, line.size() - p - 8);
            stringstream ss(classname);
            string word;
            vector<string> classes;
            while (getline(ss, word, '-')) {
                classes.push_back(word);
            }
            reverse(classes.begin(), classes.end());

            // cout << classes.size() << "\n";
            // for (int j = 0; j < classes.size(); j++) {
            //     cout << classes[j] << " ";
            // }
            // cout << "\n";

            Person person = {name, classes};
            res[i] = person;
        }

        sort(res.begin(), res.end(), [](const Person &a, const Person &b) {
            int maxlen = max(a.classes.size(), b.classes.size());
            for (int i = 0; i < maxlen; i++) {
                string strA = i < a.classes.size() ? a.classes[i] : "middle";
                string strB = i < b.classes.size() ? b.classes[i] : "middle";

                int vA = 0;
                int vB = 0;

                if (strA == "upper") {
                    vA = 3;
                } else if (strA == "middle") {
                    vA = 2;
                } else {
                    vA = 1;
                }

                if (strB == "upper") {
                    vB = 3;
                } else if (strB == "middle") {
                    vB = 2;
                } else {
                    vB = 1;
                }

                if (vA == vB) continue;
                return vA > vB;
            }
            return a.name < b.name;
        });

        for (int i = 0; i < n; i++) {
            cout << res[i].name << "\n";
        }
        cout << "==============================" << "\n";
    }
}