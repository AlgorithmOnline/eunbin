#include<bits/stdc++.h>
using namespace std;
int rt,cnt,n, m, arr[104][104], visited[104][104], dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
vector<pair<int, int>> v;
void dfs(int y,int x) {
	if (arr[y][x] == 1) {
		v.push_back({ y,x });
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny >= n || nx<0 || nx>=m || visited[ny][nx])continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}
int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (true) {
		
		memset(visited, 0, sizeof(visited));
		v.clear();
		visited[0][0] = 1;
		dfs(0, 0);
		if (v.size() == 0)break;
		rt++;
		cnt = v.size();
		for (auto a : v) {
			arr[a.first][a.second] = 0;
		}
	}
	cout <<rt<<"\n"<< cnt << "\n";
	
}
