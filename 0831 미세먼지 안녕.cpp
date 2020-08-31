#include<iostream>
#include <cstring>
using namespace std;
int sum, f_y, f_x, s_y, s_x, r, c, t, a[54][54], v[54][54], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };

void spread(int y, int x) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny<1 || ny>r || nx<1 || nx>c)continue;
        if (a[ny][nx] == -1)continue;
        v[ny][nx] += a[y][x] / 5;
        cnt++;
    }
    a[y][x] -= (a[y][x] / 5) * cnt;
}

void spread_sum() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            a[i][j] += v[i][j];
        }
    }
}
void cir() {
    for (int i = f_y - 1; i > 1; i--)a[i][1] = a[i - 1][1];
    for (int i = 1; i <= c - 1; i++)a[1][i] = a[1][i + 1];
    for (int i = 1; i <= f_y - 1; i++)a[i][c] = a[i + 1][c];
    for (int i = c; i >= f_x + 2; i--)a[f_y][i] = a[f_y][i - 1];
    a[f_y][f_x + 1] = 0;
    for (int i = s_y + 1; i < r; i++)a[i][1] = a[i + 1][1];
    for (int i = 1; i <= c - 1; i++)a[r][i] = a[r][i + 1];
    for (int i = r; i > s_y; i--)a[i][c] = a[i - 1][c];
    for (int i = c; i >= s_x+2; i--)a[s_y][i] = a[s_y][i - 1];
    a[s_y][s_x + 1] = 0;
}

int main()
{
    cin >> r >> c >> t;

    bool flag = false;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) {
                if (flag == false) {
                    f_y = i;
                    f_x = j;
                    flag = true;
                }
                else {
                    s_y = i;
                    s_x = j;
                }
            }
        }
    }
    while (t--) {
        memset(v, 0, sizeof(v));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (a[i][j] != 0 && a[i][j] != -1) spread(i, j);
            }
        }
        spread_sum();
        cir();
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[i][j] != 0 && a[i][j] != -1) sum += a[i][j];
        }
    }
    cout << sum;
}
