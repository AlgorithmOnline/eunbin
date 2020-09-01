#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
string s, t;
vector<string> v;
bool comp(string a, string b) {
    if (a.size() == b.size())return a < b;
    return a.size() < b.size();
}

void go() {
    if (t.size()) {
        while (true) {
            if (t.size() && t.front() == '0') t.erase(t.begin());
            else break;
        }
        if (t.size() == 0) t = "0";
        v.push_back(t);
        t = "";
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] < 58) t += s[j];
            else go();
        }
        go();
    }
    sort(v.begin(), v.end(), comp);
    for (string i : v) cout << i << "\n";
}
