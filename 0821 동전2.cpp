#include <bits/stdc++.h>

using namespace std;
int n, k, dp[10001], w[101];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		dp[i] = 10001;
	}
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		for (int j = w[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - w[i]] + 1);
		}
	}
	if (dp[k] == 10001)cout << -1;
	else cout << dp[k];
}
