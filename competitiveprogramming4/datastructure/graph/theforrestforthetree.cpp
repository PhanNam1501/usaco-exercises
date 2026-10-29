#include<bits/stdc++.h>
using namespace std;

void buildtree(int start, int prev, unordered_map<int, bool> &visited, vector<vector<int>> &AM, bool &check) {
    visited[start] = true;
    vector<int> vnext = AM[start];
    for (int i = 0; i < vnext.size(); i++) {
        if (visited[vnext[i]]) {
            if (prev != vnext[i]) {
                check = false;
            }
            continue;
        }
        buildtree(vnext[i], start, visited, AM, check);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        vector<vector<int>> edges;
        while (cin >> s) {
            if (s[0] == '*') break;
            s = s.substr(1, 3);
            stringstream ss(s);
            string token;
            vector<int> p;
            while (getline(ss, token, ',')) {
                char c = token[0];
                p.push_back(int(c - 'A'));
            }
            edges.push_back(p);
        }
        vector<vector<int>> AM(27);
        for (int i = 0; i < edges.size(); i++) {
            AM[edges[i][0]].push_back(edges[i][1]);
            AM[edges[i][1]].push_back(edges[i][0]);
        }
        vector<char> vertices;
        string points;
        cin >> points;
        stringstream ss(points);
        string token;
        while (getline(ss, token, ',')) {
            vertices.push_back(token[0]);
        }
        int n = vertices.size();
        vector<int> countIn(27);
        vector<int> countOut(27);
        for (int i = 0; i < edges.size(); i++) {
            countIn[edges[i][1]]++;
            countIn[edges[i][0]]++;
            countOut[edges[i][0]]++;
            countOut[edges[i][1]]++;
        }
        int trees = 0;
        int acorns = 0;
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++) {
            int v = int(vertices[i] - 'A');
            if (visited[v]) continue;
            if (countIn[v] == 0 && countOut[v] == 0) {
                acorns++;
                visited[v] = true;
            } else if (countIn[v] == 1) { 
                bool check = true;
                buildtree(v, -1, visited, AM, check);
                if (check) {
                    trees++;
                }
            }
        }

        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n"; 
    }
}