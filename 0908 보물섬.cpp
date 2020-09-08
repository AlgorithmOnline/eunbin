#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m, dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 }, mx, v[100][100];
char a[100][100];
int bfs(int y, int x) {
	queue<pair<int, int>> q;
	int t = 0;
	memset(v, 0, sizeof(v));
	q.push({ y,x });
	v[y][x] = 1;

	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
			if (a[ny][nx] == 'W' || v[ny][nx] != 0)continue;
			q.push({ ny,nx });
			v[ny][nx] = v[y][x] + 1;
			t = max(t, v[ny][nx]);
		}
	}
	return t - 1;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'L')mx = max(mx, bfs(i, j));
		}
	}
	cout << mx;
}
