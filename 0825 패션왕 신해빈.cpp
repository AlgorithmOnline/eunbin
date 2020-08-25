#include <bits/stdc++.h>

using namespace std;

int t, n,sum;
string f, s;

int main() {
	cin >> t;
	while (t--) {
		map<string, int> m;
		cin >> n;
		while (n--) {
			cin >> f >> s;
			m[s]++;
		}
		sum = 1;
		for (auto a : m) {
			sum *= (a.second+1);
		}
		cout << sum - 1 << "\n";
	}
}
