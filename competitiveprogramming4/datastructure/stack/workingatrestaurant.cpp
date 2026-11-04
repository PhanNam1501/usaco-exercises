#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    bool first = false;
    
    while (cin >> N && N != 0) {
        if (first) {
            cout << "\n";
        } else {
            first = true;
        }
        
        int pile1 = 0; 
        int pile2 = 0; 
        
        while (N--) {
            string s;
            int x;
            cin >> s >> x;
            
            if (s == "DROP") {
                cout << "DROP 2 " << x << "\n";
                pile2 += x;
            } else if (s == "TAKE") {
                if (pile1 < x) {
                    if (pile1 > 0) {
                        cout << "TAKE 1 " << pile1 << "\n";
                        x -= pile1;
                        pile1 = 0;
                    }
                    if (pile2 > 0) {
                        cout << "MOVE 2->1 " << pile2 << "\n";
                        pile1 += pile2;
                        pile2 = 0;
                    }
                }
                if (x > 0) {
                    cout << "TAKE 1 " << x << "\n";
                    pile1 -= x;
                }
            }
        }
    }
    return 0;
}