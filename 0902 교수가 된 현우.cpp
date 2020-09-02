#include <bits/stdc++.h>

using namespace std;

int n1, n2,n,d;
int main() {
	cin >> n;
	while (n--) {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> d;
		n1 = 0; n2 = 0;
		for (int i = 2; i <= d; i *= 2) {
			n1 += d / i;
		}
		for (int i = 5; i <= d; i *= 5) {
			n2 += d / i;
		}
		cout << min(n1, n2) << "\n";
	}
}
