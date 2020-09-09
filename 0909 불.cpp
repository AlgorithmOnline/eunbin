#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int m=987654321,r, c, fy, fx, jy, jx, jvisited[1500][1500],fvisited[1500][1500], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
char a[1500][1500];
queue<pair<int, int>> fq;

void bfsF() {
    while (fq.size()) {
        int y = fq.front().first;
        int x = fq.front().second;
        fq.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c)continue;
            if (a[ny][nx] == '#' || fvisited[ny][nx])continue;
            fvisited[ny][nx] = fvisited[y][x] + 1;
            fq.push({ ny,nx });
        }
    }
}

void bfsJ(int y, int x) {
    queue<pair<int, int>> q;

    jvisited[y][x] = 1;
    q.push({ y,x });

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c)continue;
            if (a[ny][nx] == '#' || jvisited[ny][nx])continue;
            if (fvisited[ny][nx] &&  jvisited[y][x] + 1 >= fvisited[ny][nx])continue;
            jvisited[ny][nx] = jvisited[y][x] + 1;
            q.push({ ny,nx });
        }
    }
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'F') {
                fq.push({ i,j });
                fvisited[i][j] = 1;
            }
            if (a[i][j] == 'J') {
                jy = i;
                jx = j;
            }
        }
    }
    bfsF();
    bfsJ(jy,jx);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {
                if(jvisited[i][j]) m = min(m, jvisited[i][j]);
            }
        }
    }
    if (m == 987654321) cout << "IMPOSSIBLE"<<"\n";
    else cout << m << "\n";
    /*
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << fvisited[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << jvisited[i][j] << " ";
        }
        cout << "\n";
    }
    */
}
