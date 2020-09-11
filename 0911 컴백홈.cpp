#include <iostream>

using namespace std;

int r, c, k, v[10][10], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
char a[10][10];

int go(int y, int x) {
    //cout << y << "," << x << "\n";
    int ret = 0;
    if (y == 0 && x == c - 1) return (v[y][x] == k);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c)continue;
        if (v[ny][nx] || a[ny][nx] == 'T')continue;
        v[ny][nx] = v[y][x] + 1;
        ret+=go(ny, nx);
        v[ny][nx] = 0;
    }
    //cout << ret << "\n";
    return ret;
}

int main()
{
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    v[r - 1][0] = 1;
    cout << go(r - 1, 0) << "\n";
}
