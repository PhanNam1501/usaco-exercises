#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int n;
    int leftcount = 0;
    int rightcount = 0;
    while (cin >> n) {
        if (leftcount == 0 && rightcount == 0) {
            max_heap.push(n);
            leftcount++;
        } else {
            if (n > max_heap.top()) {
                min_heap.push(n);
                rightcount++;
            } else {
                max_heap.push(n);
                leftcount++;
            }
        }

        if (leftcount < rightcount-1) {
            int t = min_heap.top();
            min_heap.pop();
            max_heap.push(t);
            leftcount++;
            rightcount--;
        } else if (rightcount < leftcount-1) {
            int t = max_heap.top();
            max_heap.pop();
            min_heap.push(t);
            leftcount--;
            rightcount++;
        }

        if (leftcount == rightcount) {
            cout << (max_heap.top() + min_heap.top()) / 2 << "\n";
        } else if (leftcount < rightcount) {
            cout << min_heap.top() << "\n";
        } else {
            cout << max_heap.top() << "\n";
        }
        
    }
}