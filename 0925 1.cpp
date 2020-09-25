#include <bits/stdc++.h>

using namespace std;

int n;

int main(){        
	while (scanf("%d", &n) != EOF) {
		int num = 1,i=1;
		while (true) {
			if (num % n == 0) {
				cout << i << "\n";
				break;
			}
			else {
				num = (num * 10) % n+1;
				i++;
			}
		}
	}
	return 0;
} 
