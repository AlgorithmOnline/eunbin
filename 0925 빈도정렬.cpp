#include <bits/stdc++.h>

using namespace std;

int n, c,t;
map<int,int> cnt;
map<int,int> pos;
vector<pair<int, int>>v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return pos[a.first] < pos[b.first];
    }
    return a.second > b.second;
}

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> t;
        cnt[t]++;

        if (pos[t] == 0) {
            pos[t] = i + 1;
        }
    }
    for (auto a : cnt) {
        v.push_back({ a.first,a.second });
    }
    sort(v.begin(), v.end(), cmp);
    for(auto a: v){
        for (int i = 0; i < a.second; i++) {
            cout << a.first << " ";
        }
    }

}
