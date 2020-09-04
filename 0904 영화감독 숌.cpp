#include <iostream>
#include <string>
using namespace std;

int N;

int main(){
    cin >> N;
    int i = 666, cnt = 0;
    for (;; i++) {
        if (to_string(i).find("666") != string::npos) {
            if (cnt == N-1) {
                cout << i;
                break;
            }
            cnt++;
        }
    }    
}
