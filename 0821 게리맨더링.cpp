#include <bits/stdc++.h>

using namespace std;
int n, p_num[11], ck[11], ck2[11],c_min=987654321;
vector<int> l, r;
vector<int> m[11];
int check(vector<int> v, int num) {
	int cnt = 1;
	queue<int> q;
	memset(ck2, 0, sizeof(ck2));

	q.push(v[0]);
	ck2[v[0]] = 1;
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < m[x].size(); i++) {
			if (ck2[m[x][i]] == 0 && ck[m[x][i]] == num) {				
				ck2[m[x][i]] = 1;
				cnt++;
				q.push(m[x][i]);
			}
		}
	}
	return cnt;
}
//하나씩 확인
void dfs(int L, int cnt) {
	if (cnt >= 1) {
		for (int i = 1; i <= n; i++) {
			if (ck[i]) l.push_back(i);
			else r.push_back(i);
		}
		if (l.size() == 0 || r.size() == 0)return;
		int ans = 0;
		ans += check(l,1);
		ans += check(r, 0);
		if (ans == n) {
			int p_left = 0, p_right = 0;
			for (int i = 0; i < l.size(); i++) {
				p_left += p_num[l[i]];
			}
			for (int i = 0; i < r.size(); i++) {
				p_right += p_num[r[i]];
			}
			int val = abs(p_left - p_right);
			if (c_min > val) c_min = val;
		}
		l.clear();
		r.clear();
	}
	
	for (int i = L; i <= n; i++) {
		if (ck[i] == 0) {
			ck[i] = 1;
			dfs(i+1,cnt+1);
			ck[i] = 0;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p_num[i];
	}
	for (int i = 1; i <= n; i++) {
		int nn = 0;
		cin >> nn;
		for (int j = 1; j <= nn; j++) {
			int a = 0;
			cin >> a;
			m[i].push_back(a);
		}
	}
	dfs(1, 0);
	if (c_min == 987654321) cout << "-1";
	else cout << c_min;
}
