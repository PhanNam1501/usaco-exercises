#include <iostream>
#include <vector>

using namespace std;

struct Flight {
    int u, v;
    long long z;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n, m;
    if (!(cin >> k >> n >> m)) return 0;

    vector<vector<Flight>> flights(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        long long z;
        cin >> u >> v >> d >> z;
        flights[d].push_back({u, v, z});
    }

    vector<vector<long long>> arr(n + 1, vector<long long>(k + 1, 0));
    for (int i = 0; i < k * n; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        arr[b][a] += c; 
    }

    vector<long long> current_passengers(k + 1, 0);

    for (int d = 1; d <= n; d++) {
        
        for (int u = 1; u <= k; u++) {
            current_passengers[u] += arr[d][u];
        }

        vector<long long> arriving_passengers(k + 1, 0);

        for (const auto& flight : flights[d]) {
            current_passengers[flight.u] -= flight.z;
            
            if (current_passengers[flight.u] < 0) {
                cout << "suboptimal\n";
                return 0;
            }
            
            arriving_passengers[flight.v] += flight.z;
        }

        for (int u = 1; u <= k; u++) {
            current_passengers[u] += arriving_passengers[u];
        }
    }

    cout << "optimal\n";
    return 0;
}