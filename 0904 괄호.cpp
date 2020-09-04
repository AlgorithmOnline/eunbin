#include <bits/stdc++.h>

using namespace std;
int T;
string st;

string check(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') stk.push(s[i]);
        else if (stk.empty()) return "NO";
        else stk.pop();
    }
    if (stk.empty()) return "YES";
    else return "NO";
}
int main()
{
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> st;
        cout << check(st) << "\n";
    }
}
