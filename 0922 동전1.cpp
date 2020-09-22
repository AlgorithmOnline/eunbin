#include <bits/stdc++.h>

using namespace std;

int n, k,dp[10001],ret,won[100];

int main()
{
    cin >> n >> k;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        cin >> won[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if(j - won[i]>=0)dp[j] += dp[j - won[i]];
        }
    }
    cout << dp[k];
}
