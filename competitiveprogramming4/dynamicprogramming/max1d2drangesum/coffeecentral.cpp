#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int dx, dy, n, q;
    int case_num = 1; 
    while (cin >> dx >> dy >> n >> q) {
        if (dx == 0 && dy == 0 && n == 0 && q == 0) break;
        
        vector<pair<int, int>> arr(n);
        vector<int> queries(q);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        for (int i = 0; i < q; i++) {
            cin >> queries[i];
        }

      
        int max_coord = dx + dy + 5;
        vector<vector<int>> mp(max_coord + 1, vector<int>(max_coord + 1, 0));
        
        for (int i = 0; i < n; i++) {
            int l = arr[i].first + arr[i].second;
            int r = arr[i].second - arr[i].first + dx;
            mp[l][r] = 1;
        }

        vector<vector<int>> dp(max_coord + 1, vector<int>(max_coord + 1, 0));
        for (int i = 1; i <= max_coord; i++) {
            for (int j = 1; j <= max_coord; j++) {
                dp[i][j] = mp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }

        cout << "Case " << case_num++ << ":\n";

        for (int i = 0; i < q; i++) {
            int k = queries[i];
            int maxx = -1;
            pair<int, int> maxres{0, 0};
            
            for (int x = 1; x <= dx; x++) {
                for (int y = 1; y <= dy; y++) {
                    int l = x + y;
                    int r = y - x + dx;
                    
                    int lup = l + k > max_coord ? max_coord : l + k;
                    int ldown = l - k - 1 < 0 ? 0 : l - k - 1;
                    int rup = r + k > max_coord ? max_coord : r + k;
                    int rdown = r - k - 1 < 0 ? 0 : r - k - 1;
                    
                    int t = dp[lup][rup] + dp[ldown][rdown] - dp[ldown][rup] - dp[lup][rdown];
                    
                    if (t > maxx) {
                        maxx = t;
                        maxres = {x, y};
                    } else if (t == maxx) {
                        if (y < maxres.second) {
                            maxres = {x, y};
                        } else if (y == maxres.second) {
                            if (x < maxres.first) {
                                maxres = {x, y};
                            }
                        }
                    }
                }
            }

            cout << maxx << " (" << maxres.first << "," << maxres.second << ")\n";
        }
    }   
}