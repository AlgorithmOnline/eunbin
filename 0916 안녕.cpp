#include <bits/stdc++.h>

using namespace std;

int n,s[24],h[24],dp[99];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 99; j >= s[i]; j--) {
			dp[j] = max(dp[j], dp[j - s[i]] + h[i]);
		}
	}
	cout << dp[99];
}
