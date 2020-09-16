#include <iostream>
#include <queue>

using namespace std;
typedef struct {
    int y;
    int x;
    int d;
}st;
queue<st> q;
int ret, n, a[20][20], dy[3] = { 0,1,1 }, dx[3] = { 1,0,1 }, cdy[2] = {0,-1}, cdx[2] = {-1,0};


int bfs(int y, int x, int d) {
    q.push({ y,x,d });
    while (!q.empty()) {
        y = q.front().y;
        x = q.front().x;
        d = q.front().d;        
        q.pop();
        if (y == n - 1 && x == n - 1) ret++;
        for (int i = 0; i < 3; i++) {
            if (d == 0 && i == 1)continue;
            if (d == 1 && i == 0)continue;
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx])continue;
            if (i != 2) {
                q.push({ ny,nx,i });
            }
            if ( i == 2) {
                bool ch = false;
                for (int j = 0; j < 2; j++) {
                    int cy = ny + cdy[j];
                    int cx = nx + cdx[j];
                    if (cy < 0 || cy >= n || cx < 0 || cx >= n || a[cy][cx]) {
                        ch = true;
                        break;
                    }
                }
                if (!ch) q.push({ ny,nx,i });
            }                     
        }
    }
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout<<bfs(0, 1, 0);
}
