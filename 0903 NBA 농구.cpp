#include <iostream>
#include <string>

using namespace std;

string a[150][2],h1,m1,h2,m2;
int n,cnt1,cnt2,win1,win2;

int countTime(string t1, string t2) {
    int h1 = stoi(t1.substr(0, 2));
    int h2 = stoi(t2.substr(0, 2));
    int m1 = stoi(t1.substr(3, 2));
    int m2 = stoi(t2.substr(3, 2));
    if (m2 > m1) {
        h2 -= 1;
        m2 += 60;
    }
    int res = ((h2 - h1) * 60) + (m2 - m1);
    //cout << h1 << "," << h2 << "," << m1 << "," << m2 << "\n";
    //cout<<res;
    return res;
}

void check() {
    if (win1 / 60 < 10)h1 = "0";
    h1 += to_string(win1 / 60);
    if (win1 % 60 < 10)m1 = "0";
    m1 += to_string(win1% 60);
    if (win2 / 60 < 10)h2 = "0";
    h2 += to_string(win2 / 60);
    if (win2 % 60 < 10)m2 = "0";
    m2 += to_string(win2 % 60);
    cout << h1 << ":" << m1 << "\n";
    cout << h2 << ":" << m2 << "\n";
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i < n; i++) {
        if (a[i][0] == "1") cnt1++;
        else cnt2++;
        if (cnt1 > cnt2) {
            if(i==n-1) win1 += countTime(a[i][1], "48:00");
            else win1 += countTime(a[i][1], a[i + 1][1]);
            //cout << "win1:" << win1 << "\n";
        }
        if (cnt1 < cnt2) {
            if(i==n-1) win2 += countTime(a[i][1], "48:00");
            else win2 += countTime(a[i][1], a[i + 1][1]);
            //cout << "win2:" << win2 << "\n";
        }
    }
    //cout.width(2);
    //cout.fill('0');
    //cout << (win1 / 60) << ":" << (win1 % 60) << "\n";
    //cout << (win2 / 60) << ":" << (win2 % 60) << "\n";
    check();
    
}
