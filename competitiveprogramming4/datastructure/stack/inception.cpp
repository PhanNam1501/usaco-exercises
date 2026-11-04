#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<string> st;
    while (n--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string command;

        ss >> command;
        if (command == "Sleep") {
            string name;
            ss >> name;
            st.push(name);
        } else if (command == "Kick") {
            if (!st.empty()) {
                st.pop();
            }
        } else if (command == "Test") {
            if (!st.empty()) {
                cout << st.top() << "\n";
            } else {
                cout << "Not in a dream\n";
            }
        }
    }
}