#include<bits/stdc++.h>
using namespace std;

int main() {
 	int N;
	cin >> N;

	vector<long long> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];	
	}

	vector<long long> pre(N+1, 0);
	unordered_map<long long, int> fexists;
	int res = 0;
	
	for (int i = 1; i <= N; i++) {
		pre[i] = pre[i-1] + arr[i-1];
		long long r = pre[i] % (7LL);
		if (r == 0) {
			res = max(res, i-0);
		} else if (fexists[r] != 0) {
			res = max(res, i - fexists[r]);
		} else {
	        	fexists[r] = i;
		}
	}
	
	cout << res << "\n";
}