#include<bits/stdc++.h>
using namespace std;

struct contest {
    int contestnumber;
    int problem;
    int time;
    char status;
};

struct result {
    int contestnumber;
    int problems;
    int score;
};

int main() {
    int T;
    cin >> T;

    string line;
    getline(cin, line);
    getline(cin, line); 
    while (T--) {
        vector<contest> arr;
        while (getline(cin, line)) {
            if (line.empty()) break;

            int contestnumber, problem, time;
            char status;

            stringstream ss(line);
            ss >> contestnumber >> problem >> time >> status;
            contest c = {contestnumber, problem, time, status};
            arr.push_back(c);
        }

        vector<result> res(101);
        unordered_map<int, unordered_set<int>> setMp;
        unordered_map<int, unordered_map<int, bool>> check;
        unordered_map<int, unordered_map<int, int>> penalty;
        for (int i = 0; i < arr.size(); i++) {
            if (check[arr[i].contestnumber][arr[i].problem]) {
                setMp[arr[i].contestnumber].insert(arr[i].problem);
                res[arr[i].contestnumber].problems = setMp[arr[i].contestnumber].size();
                continue;
            }

            if (arr[i].status == 'C') {
                check[arr[i].contestnumber][arr[i].problem] = true;
                setMp[arr[i].contestnumber].insert(arr[i].problem);
                res[arr[i].contestnumber].problems = setMp[arr[i].contestnumber].size();
                res[arr[i].contestnumber].score += arr[i].time;
                res[arr[i].contestnumber].score += penalty[arr[i].contestnumber][arr[i].problem];
            } else if (arr[i].status == 'I') {
                penalty[arr[i].contestnumber][arr[i].problem] += 20;
            }

            res[arr[i].contestnumber].contestnumber = arr[i].contestnumber;
        }


        sort(res.begin(), res.end(), [](const result& a, const result& b) {
            if (a.problems == b.problems) {
                if (a.score == b.score) {
                    return a.contestnumber < b.contestnumber;
                }
                return a.score < b.score;
            }
            return a.problems > b.problems;
        });

        for (int i = 0; i < 101; i++) {
            if (res[i].contestnumber != 0) {
                cout << res[i].contestnumber << " " << res[i].problems << " " << res[i].score << "\n";
            }
        }

        if (T > 0) cout << "\n";
    }
}