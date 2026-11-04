#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0; 

    vector<int> positions;
    positions.push_back(0); 

    while (k--) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "undo") {
            int m;
            cin >> m; 
            while (m--) {
                positions.pop_back();
            }
        } else {
            int p = stoi(cmd); 
            
            int current_pos = positions.back(); 
            
            int next_pos = ((current_pos + p) % n + n) % n;
            
            positions.push_back(next_pos);
        }
    }

    cout << positions.back() << "\n";
    
    return 0;
}