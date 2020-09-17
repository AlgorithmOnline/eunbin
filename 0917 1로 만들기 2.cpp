#include <bits/stdc++.h>

using namespace std;

int n,dp[1000001],INF=987654321;

void go(int n) {
    
    cout << n << " ";
    if (n == 1) return;
    if (n % 3 == 0 && dp[n / 3] + 1 == dp[n]) go(n / 3);
    else if (n % 2 == 0 && dp[n / 2] + 1 == dp[n]) go(n / 2);
    else go(n - 1);
}

int main()
{
    cin >> n;
    fill(dp, dp + 1000001, INF);
   
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++) {
        
        if (i % 3 == 0) {
            dp[i]=min(dp[i / 3] + 1,dp[i]);
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        }
        
        dp[i] = min(dp[i-1] + 1, dp[i]);
        
    }
    cout << dp[n] << "\n";
    go(n);
}
