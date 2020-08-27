#include <iostream>
#include <string>
#include <stack>

using namespace std;
string st;

string check(string s) {
    string ans = "yes";
    stack<char> stk;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[') {
            stk.push(s[i]);
        }
        if (s[i] == ')' || s[i] == ']') {
            if (stk.empty()) {
                ans = "no";
                break;
            }
            else if (stk.top() == '(' && s[i] == ']') {
                ans = "no";
                break;
            }
            else if (stk.top() == '[' && s[i] == ')') {
                ans = "no";
                break;
            }
            else if (stk.top() == '[' && s[i] == ']') {
                stk.pop();
            }
            else if (stk.top() == '(' && s[i] == ')') {
                stk.pop();
            }
            else;
        }
    }
    if (!stk.empty()) ans = "no";
    return ans;
}
int main()
{
    getline(cin, st);
    while (st != ".") {
        cout << check(st) << "\n";
        getline(cin, st);
    }    
}
