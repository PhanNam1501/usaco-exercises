#include<bits/stdc++.h>
using namespace std;

int N, M, C;
vector<int> cities;
vector<pair<int, int>> roads;
vector<vector<int>> ways;
int res = 0;


int main() {
    cin >> N >> M >> C;

    cities.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cities[i];
    }

    roads.resize(M);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        roads[i] = pair<int, int>{x, y};
    }

    ways.resize(N+1);
    for (int i = 0; i < M; i++) {
        ways[roads[i].second].push_back(roads[i].first);
    }

    vector<vector<int>> dp(1005, vector<int>(N+1, -1));
    dp[0][1] = 0;

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= N; j++) {
            for (int r = 0; r < ways[j].size(); r++) {
                if (dp[i-1][ways[j][r]] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i-1][ways[j][r]] + cities[j-1]);
                }
            }

            if (j == 1) { 
                res = max(res, dp[i][j] - C * i * i);
            }
        }

        
    }   
    
    cout << res << "\n";
}