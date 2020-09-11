#include <iostream>
#include <algorithm>

using namespace std;
int n, ret=987654321, a[20][20], v[20][20], p[20][20], dy[4] = { -1,1,0,0 }, dx[4] = {0,0,-1,1};

int check(int y, int x) {
    
    if (v[y][x]) return 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny<0 || ny>=n || nx < 0 || nx >= n) {
            return 0;
        }
        if (v[ny][nx])return 0;
    }  
    return 1;
}

int setFlower(int y, int x) {
    int s = 0;
    v[y][x] = 1;
    s += p[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        v[ny][nx] = 1;
        s += p[ny][nx];
    }
    return s;
}

void eraseV(int y, int x) {
    v[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        v[ny][nx] = 0;
    }
    
}
void flower(int cnt,int hap) {
    if (cnt == 3) {
        ret = min(ret, hap);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int p = check(i, j);
            if (p) {
                int sum=setFlower(i, j);
                flower(cnt+1,hap+sum);
                
                eraseV(i, j);
            }
        }
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    flower(0, 0);
    cout << ret;
}
