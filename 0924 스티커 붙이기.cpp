#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int r, c;
int sticker[10][10];
bool _map[40][40];
int tmparr[10][10];

bool check(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j]==1 && _map[i + x][j + y])return false;
		}
	}
	return true;
}
void putSticker(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j]==1) _map[i + x][j + y]=1;
		}
	}
}
bool solve() {
	for (int i = 0; i <= n - r; i++) {
		for (int j = 0; j <= m - c; j++) {
			if (check(i, j)) {
				putSticker(i,j);
				return true;
			}
		}
	}
	return false;
}

void rotate() {
	memset(tmparr, 0, sizeof(tmparr));
	for (int i = 0; i < c; i++) {
		for (int j = 0, l = r - 1; j < r; j++, l--) {
			tmparr[i][j] = sticker[l][i];
		}
	}
	int temp = r;
	r = c;
	c = temp;
	memset(sticker, 0, sizeof(sticker));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sticker[i][j]=tmparr[i][j];
		}
	}
}

int main() {
	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
			}
		}
		bool flag = false;
		for (int k = 0; k < 4; k++) {
			if (solve())break;
			else rotate();
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (_map[i][j]) cnt++;
		}
	}
	cout << cnt;
}
