#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int r ,c , maximum, arr[8][8], arrcopy[8][8], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
bool visit[8][8];

int count() {
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arrcopy[i][j] == 0) cnt++;
        }
    }
    return cnt;

}
void virus() {
    memcpy(&arrcopy, &arr, sizeof(arr));
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arrcopy[i][j] == 2) {
                q.push(make_pair(i, j));
                visit[i][j] = true;
            }

            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < r && ny>=0 && ny < c) {
                        if (arrcopy[nx][ny] == 0 && !visit[nx][ny]) {
                            q.push(make_pair(nx, ny));
                            visit[nx][ny] = true;
                            arrcopy[nx][ny] = 2;
                        }
                    }
                }
            }          
        }
    }
    int ans = count();
    if (ans > maximum) maximum = ans;

}
void wall(int cnt) {
    if (cnt == 3) {
        
        virus();
        return;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                wall(cnt + 1);
                arr[i][j] = 0;
            }
        }
    }
}
int main()
{
    cin >> r >> c;    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    wall(0);
    cout << maximum;
}
