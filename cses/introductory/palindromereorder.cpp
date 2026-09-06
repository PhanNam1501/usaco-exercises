#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.size();
	
	unordered_map<char, int> cnt;
	for (int i = 0; i < n; i++) {
		cnt[s[i]]++;
	} 
	int cntOne = 0;
	for (auto& [key, value] : cnt) {
 		if (value % 2 == 1) cntOne++;
	}
	if (cntOne > 1) {
		cout << "NO SOLUTION" << "\n";
		return 0;
	}
	vector<char> ch(n, ' ');
	int l = 0;
	int r = n - 1;
	for (auto& [key, value] : cnt) {
		if (value % 2 == 1) {
	        	ch[n/2] = key;
			for (int i = 0; i < value/2; i++) {
				ch[n/2-i-1] = key;
				ch[n/2+i+1] = key;
			}
			continue;
		}
		for (int i = 0; i < value/2; i++) {
			ch[l] = key;
			l++;
			ch[r] = key;
			r--;
		}
	}
	string res(ch.begin(), ch.end());
	cout << res << "\n";
}