using namespace std;

#include <iostream>

int h, w;
char a[150][150];
int b[150][150],cnt;

int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        cnt = -1;
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 'c') {
                cnt = -1;
                b[i][j] = ++cnt;
            }
            if (cnt != -1 && a[i][j] == '.') {
                b[i][j] = ++cnt;
            }
            if (cnt == -1 && a[i][j] == '.') {
                b[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}

