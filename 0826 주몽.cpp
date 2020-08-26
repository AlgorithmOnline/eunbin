#include <bits/stdc++.h>

using namespace std;

int rs, s[20000],m,n;

int main(){
    cin >> n>>m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (s[i] + s[j] == m) rs++;
       }
    }
    cout << rs;
}
