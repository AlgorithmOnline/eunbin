#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,from,to,cnt;
vector<pair<int, int>> v;
int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> from >> to;
        v.push_back({ to,from });
    }
    sort(v.begin(), v.end());

    int start = v[0].second;
    int end = v[0].first;
    for (int i = 1; i < v.size(); i++) {
        if (end <= v[i].second) {
            
            start = v[i].second;
            end = v[i].first;
            cnt++;

        }
    }
    cout << cnt+1;

}
