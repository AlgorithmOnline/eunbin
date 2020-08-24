#include <bits/stdc++.h>

using namespace std;

int n, sum, t, mx = -1004;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		mx = max(t, mx);
		if (sum + t > 0) {
			mx = max(sum + t, mx);
			sum += t;
		}
		else sum = 0;
	}
	cout << mx;
}
