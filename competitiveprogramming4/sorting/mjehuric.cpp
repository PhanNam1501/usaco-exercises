#include<bits/stdc++.h>
using namespace std;

void checkpoint(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (i == arr.size()-1) {
            cout << arr[i] << "\n";
        } else {
            cout << arr[i] << " ";
        }
    }
}

int main() {
    vector<int> arr(5);
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                checkpoint(arr);
            }
        }
    }
}