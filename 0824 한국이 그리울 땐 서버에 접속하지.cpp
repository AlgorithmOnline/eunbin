#include <bits/stdc++.h>

using namespace std;
int n;
string s,t;

int main() {
	cin >> n>>s;
	int p = s.find('*');
	string f=s.substr(0, p);
	string r = s.substr(p + 1);
	while (n--) {
		string rs = "DA";
		cin >> t;
		int fl = f.length(), rl = r.length(),tl = t.length();
		if (fl + rl > tl) rs = "NE";
		for (int i = 0; i < fl; i++) {
			if(f[i]!=t[i]) rs = "NE";
		}
		for (int i = 0; i < rl; i++) {
			if (r[i] != t[tl-rl+i]) rs = "NE";
		}
		cout << rs << "\n";
	}	
}
