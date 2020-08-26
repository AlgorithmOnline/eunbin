#include <iostream>
using namespace std;
string s,ret;
int c[200],t;
char mid;
int main() {
	cin >> s;
	for (auto a : s) {
		c[a]++;
	}
	for (int a = 'Z'; a >= 'A'; a--) {
		if (c[a]) {
			if (c[a] & 1) {
				mid = char(a);
				t++;
				c[a]--;
			}
			if (t == 2) break;
			for (int i = 0; i < c[a]; i += 2) {
				ret = char(a) + ret;
				ret += char(a);
			}
		}
	}
	if (mid) ret.insert(ret.begin() + ret.size() / 2, mid);
	if (t == 2)cout << "I'm Sorry Hansoo";
	else cout << ret;
}
