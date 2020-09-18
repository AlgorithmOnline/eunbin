#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, ans;
const int INF = 987987987;
int board[22][22], vis[22][22];
int curR, curC,curCnt,curN;
int dr[4] = { -1,1,0,0 }, dc[4] = { 0,0,-1,1 };
vector<pair<int, int>> ed;
bool isRange(int r, int c) {
	if (r<1 || r>N || c<1 || c>N)return false;
	return true;
}
void initVis() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vis[i][j] = -1;
		}
	}
}
bool find() {
	initVis();

	queue<pair<int, int>> Q;
	Q.push({ curR,curC });
	vis[curR][curC] = 0;

	int dist = INF, nextR = -1, nextC = -1;
	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();
		if (board[r][c] > 1) {
			if (dist > vis[r][c]) {
				dist = vis[r][c];
				nextR = r;
				nextC = c;
			}
			else if (dist == vis[r][c]) {
				if (nextR > r) {
					nextR = r;
					nextC = c;
				}
				else if (nextR == r) {
					if (nextC > c) {
						nextC = c;
					}
				}
			}
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (!isRange(nr, nc) || vis[nr][nc] != -1 || board[nr][nc] == 1)continue;
			vis[nr][nc] = vis[r][c] + 1;
			Q.push({ nr,nc });
		}
	}
	if (dist == INF || dist > ans) {
		ans = -1;
		return false;
	}
	ans -= dist;
	curR = nextR;
	curC = nextC;
	curN = board[nextR][nextC];
	board[nextR][nextC] = 0;

	return true;
}
bool move() {
	initVis();

	queue<pair<int, int>> Q;
	vis[curR][curC] = 0;
	Q.push({ curR,curC });

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		if (r == ed[curN].first && c == ed[curN].second) {
			if (ans >= vis[r][c]) {
				ans += vis[r][c];
				curR = r;
				curC = c;
				curCnt++;
				return true;
			}
			else {
				ans = -1;
				return false;
			}
		}
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (!isRange(nr, nr) || vis[nr][nc] != -1 || board[nr][nc] == 1)continue;
			vis[nr][nc] = vis[r][c] + 1;
			Q.push({ nr,nc });
		}
	}
	ans = -1;
	return false;
	
}
int main() {
	cin >> N >> M >> ans;
	ed.resize(M + 2);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
	cin >> curR >> curC;
	for (int i = 1; i <= M; i++) {
		int r, c;
		cin >> r >> c >> ed[i + 1].first >> ed[i + 1].second;
		board[r][c] = i + 1;
	}
	while (curCnt < M) {
		if (!find())break;
		if (!move())break;
	}
	cout << ans;
}
