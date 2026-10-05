#include<bits/stdc++.h>
using namespace std;

struct Info {
    string name;
    int day;
    int month;
    int year;
};

int main() {
    int n;
    cin >> n;
    vector<Info> arr(n);
    for (int i = 0; i < n; i++) {
        string name;
        int day, month, year;
        cin >> name >> day >> month >> year;
        Info info = {name, day, month, year};
        arr[i] = info;
    }

    sort(arr.begin(), arr.end(), [](Info a, Info b) {
        if (a.year == b.year) {
            if (a.month == b.month) {
                return a.day < b.day;
            }
            return a.month < b.month;
        }
        return a.year < b.year;
    });

    cout << arr[n-1].name << "\n";
    cout << arr[0].name << "\n";
}