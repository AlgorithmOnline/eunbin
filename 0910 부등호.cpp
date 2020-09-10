#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int k, visit[10];
char v[10];
vector<string> ans;

bool good(char op, char left, char right) {
	if (op == '<' && left < right) return true;
	if (op == '>' && left > right) return true;
	return false;
}

void go(int idx, string st) {
	if (idx == k+1) {  
		ans.push_back(st);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (visit[i] == 1)continue;
		if (idx == 0 || good(v[idx - 1], st[idx - 1], i + '0') ) {
			visit[i] = 1;
			go(idx + 1, st + to_string(i));
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) cin >> v[i];
	go(0, "");
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << "\n" << ans[0];
}
