#include <bits/stdc++.h>

using namespace std;

int rs,dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 }, hap, n, l, r, a[54][54], visited[54][54];
vector<pair<int, int>>v;

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
			if (visited[ny][nx])continue;
			int c = abs(a[y][x] - a[ny][nx]);
			if (c<l || c>r)continue;
			hap += a[ny][nx];
			v.push_back({ ny,nx });
			visited[ny][nx] = 1;
			dfs(ny, nx);
		}
	}
}

int main() {
	cin >> n>>l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	while (true) {
		bool flag = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0) {
					hap = a[i][j];
					visited[i][j] = 1;
					v.push_back({ i,j });
					dfs(i, j);
					if (v.size() >= 2) flag = 1;
					for (auto t : v) {
						a[t.first][t.second] = hap / v.size();
					}
					v.clear();
				}
			}
		}
		if (!flag) break;
		rs++;
	}
	cout << rs;
	
}
