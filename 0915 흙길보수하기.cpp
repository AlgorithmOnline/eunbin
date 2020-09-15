#include <bits/stdc++.h>

using namespace std;
int n, l,f,s,h,cnt;
vector<pair<int, int>>v;
int main() {
	cin >> n >> l;
	while (n--) {
		cin >> f >> s;
		v.push_back({ f,s });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (h < v[i].first) h = v[i].first;
		while (h < v[i].second) {
			h += l;
			cnt++;
		}
	}
	cout << cnt;
}
