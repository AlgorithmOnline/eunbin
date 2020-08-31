#include <bits/stdc++.h>

using namespace std;

int n, c,dp[10001];
double m, p;

int main(){
	while (true) {
		memset(dp, 0, sizeof(dp));
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		int money = (int)(m * 100 + 0.5);
		for (int i = 0; i < n; i++) {
			cin >> c >> p;
			int price=(int)(p * 100 + 0.5);
			for (int j = price; j <= money; j++) {
				dp[j] = max(dp[j], dp[j - price] + c);
			}
		}
		cout << dp[money]<<"\n";
	}
}
