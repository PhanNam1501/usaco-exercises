#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    int id;

    bool operator<(const Node& other) const {
        return value != other.value
            ? value < other.value
            : id > other.id;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> arr(M);
    for (int i = 0; i < M; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    unordered_map<int, int> cnt;
    vector<vector<int>> votes(N+1);
    set<Node> s;
    for (int i = 0; i < M; i++) {
        votes[arr[i].first].push_back(arr[i].second);
        cnt[arr[i].first]++;
    }
    for (int i = 1; i <= N; i++) {
        s.insert({cnt[i], i});
    }

    for (int i = 1; i <= N; i++) {
        s.erase({cnt[i], i});
        for (int b : votes[i]) {
            s.erase({cnt[b], b});
            cnt[b]++;
            s.insert({cnt[b], b});
        }
        cout << s.rbegin()->id << '\n';
        for (int b : votes[i]) {
            s.erase({cnt[b], b});
            cnt[b]--;
            s.insert({cnt[b], b});
        }
        s.insert({cnt[i], i});
    }
}