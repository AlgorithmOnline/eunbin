#include <bits/stdc++.h>

using namespace std;

int p[4], t[101],s,f,rs;

int main()
{
    for (int i = 1; i <= 3; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= 3; i++) {
        cin >> s >> f;
        for (int j = s; j < f; j++) {
            t[j] += 1;
        }
    }
    for (int i = 1; i <= 100; i++) {
        if (t[i] == 1) rs += t[i] * p[1];
        else if (t[i] == 2) rs += t[i] * p[2];
        else if(t[i] == 3) rs += t[i] * p[3];
        else ;
    }
    cout << rs;
}
