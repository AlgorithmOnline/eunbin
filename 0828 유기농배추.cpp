#include <iostream>
#include <cstring>
using namespace std;

int cnt, visited[50][50], arr[50][50], T, M, N, K, X, Y, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N)continue;
		if (arr[nx][ny] == 0 || visited[nx][ny] != 0)continue;
		visited[nx][ny] = 1;
		dfs(nx, ny);

	}
	return;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			arr[X][Y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1 && visited[i][j] == 0) {
					
					cnt++;
					visited[i][j] = 1;
					dfs(i, j);
				}
			}
		}
		cout << cnt << "\n";
		cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
	}
}
