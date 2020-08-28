#include <iostream>
#include <queue>

using namespace std;

int N, M, arr[100][100], visited[100][100], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
queue<pair<int, int>>q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (arr[nx][ny] == 0 || visited[nx][ny] != 0)continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx,ny });
		}
	}
	
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	visited[0][0] = 1;
	q.push({ 0,0 });
	bfs();
	cout << visited[N - 1][M - 1];
}
