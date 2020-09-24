#include <bits/stdc++.h>

using namespace std;

int t, n,tp;

int main(){        
    cin >> t;
    while (t--) {
        cin >> n;
        int mx = -1004,sum=0;
        for (int i = 0; i < n; i++) {
            cin >> tp;
            mx = max(tp, mx);
            if (sum + tp > 0) {
                mx = max(sum + tp, mx);
                sum += tp;
            }
            else sum = 0;
        }
        cout << mx << "\n";
    }
} 
