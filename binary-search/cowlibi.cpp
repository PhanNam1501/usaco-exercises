#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y, t;
};

int bs(vector<Point>& grazed, long long t) {
    int l = 0;
    int r = grazed.size();

    while (l < r) {
        int m = l + (r - l) / 2;

        if (grazed[m].t <= t) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l;
}

bool canReach(Point a, Point b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long dt = a.t - b.t;

    return dx * dx + dy * dy <= dt * dt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int G, N;
    cin >> G >> N;

    vector<Point> grazed(G);

    for (int i = 0; i < G; i++) {
        cin >> grazed[i].x >> grazed[i].y >> grazed[i].t;
    }

    sort(grazed.begin(), grazed.end(), [](const Point& a, const Point& b) {
        return a.t < b.t;
    });

    int innocent = 0;

    for (int i = 0; i < N; i++) {
        Point cow;
        cin >> cow.x >> cow.y >> cow.t;

        int t = bs(grazed, cow.t);

        bool possible = true;

        if (t > 0) {
            if (!canReach(cow, grazed[t - 1])) {
                possible = false;
            }
        }

        if (t < G) {
            if (!canReach(grazed[t], cow)) {
                possible = false;
            }
        }

        if (!possible) {
            innocent++;
        }
    }

    cout << innocent << '\n';

    return 0;
}