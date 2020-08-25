#include <iostream>
#include <map>

using namespace std;

int N, M;
map<string, int> m1;
map<int, string> m2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s = "";
		cin >> s;
		m1.insert({ s, i + 1 });
		m2.insert({ i + 1,s });
	}
	for (int i = 0; i < M; i++) {
		string s = "";
		cin >> s;
		if (atoi(s.c_str()) == 0) {
			cout << m1[s] << "\n";
		}
		else {
			cout << m2[atoi(s.c_str())] << "\n";
		}
	}
}
