#include<bits/stdc++.h>
using namespace std;

int ways = 0;
vector<bool> row(8);
vector<bool> col(8);
vector<bool> leftcross(15);
vector<bool> rightcross(15);
vector<vector<bool>> visited(8, vector<bool>(8, false));

void backtrack(int n) {
    if (n == 8) {
        ways++;
        return;
    }
   
    for (int i = 0; i < 8; i++) {
        if (!col[i] && !leftcross[i-n+7] && !rightcross[n+i] && !visited[n][i]) {
            col[i] = true;
            leftcross[i-n+7] = true;
            rightcross[n+i] = true;
            backtrack(n+1);
            col[i] = false;
            leftcross[i-n+7] = false;
            rightcross[n+i] = false;
        }
    }
}

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == '*') {
                // row[i] = true;
                // col[i] = true;
                // leftcross[j-i+7] = true;
                // rightcross[i+j] = true;
                visited[i][j] = true;
            }
        }
    }

    backtrack(0);
    cout << ways << "\n";
}