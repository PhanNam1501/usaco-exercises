#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> g(N);
    for (int i = 0; i < N; i++) cin >> g[i];

    const ll INF = 1e18;

    vector<vector<vector<ll>>> dp(
        N + 1,
        vector<vector<ll>>(K + 1, vector<ll>(N, INF))
    );

    for (int ki = 0; ki < N; ki++) {
        if (g[ki] >= g[0])
            dp[1][0][ki] = g[ki] - g[0];
    }

    for (int i = 2; i <= N; i++) {
        vector<ll> best(K + 1, INF);
        for (int j = 0; j <= K; j++)
            for (int pi = 0; pi < N; pi++)
                best[j] = min(best[j], dp[i-1][j][pi]);

        for (int j = 0; j <= K; j++) {
            for (int ki = 0; ki < N; ki++) {
                int k = g[ki];
                if (k < g[i-1]) continue; 

                if (dp[i-1][j][ki] != INF)
                    dp[i][j][ki] = min(dp[i][j][ki],
                                       dp[i-1][j][ki] + (k - g[i-1]));

                if (j > 0 && best[j-1] != INF)
                    dp[i][j][ki] = min(dp[i][j][ki],
                                       best[j-1] + (k - g[i-1]));
            }
        }
    }

    ll ans = INF;
    for (int j = 0; j <= K; j++)
        for (int ki = 0; ki < N; ki++)
            ans = min(ans, dp[N][j][ki]);

    cout << ans << '\n';
}