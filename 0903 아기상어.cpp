#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
int cnt, n, rs, dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 },sharkY,sharkX,sharkSize=2,a[50][50];
using namespace std;
struct fish {
	int y, x, d;
	bool operator < (fish& a)const {
		if (d == a.d) {
			if (y == a.y) {
				return x < a.x;
			}
			return y < a.y;
		}
		return d < a.d;
	}
};
int bfs(int fy, int fx) {
	queue<pair<int, int>> q;
	int v[50][50] = { 0 };

	q.push({ sharkY,sharkX });
	v[sharkY][sharkX] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
			if (v[ny][nx] != 0 || a[ny][nx] > sharkSize)continue;
			v[ny][nx] = v[y][x] + 1;
			q.push({ ny,nx });
			if (ny == fy && nx == fx)return v[ny][nx] - 1;
		}
	}
	return 0;
}
void solve() {
	vector<fish> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 0 && a[i][j] < sharkSize) {
				int d = bfs(i, j);
				if (d) v.push_back({ i,j,d });
			}
		}
	}
	if (v.size()) {
		sort(v.begin(), v.end());
		rs += v[0].d;
		a[sharkY][sharkX] = 0;
		sharkY = v[0].y;
		sharkX = v[0].x;
		if (++cnt == sharkSize) {
			cnt = 0;
			sharkSize += 1;
		}
		solve();
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				sharkY = i;
				sharkX = j;
			}
		}
	}
	solve();
	cout << rs;
}
