using namespace std;

#include <iostream>
#include <string>

string st;
bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}
bool f1(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            //cout << "here 1" << "\n";
            return true;

    }
    return false;
}

bool f2(string s) {
    if (s.length() >= 3) {
        for (int i = 0; i < s.length() - 2; i++) {
            if (isVowel(s[i]) && isVowel(s[i + 1]) && isVowel(s[i + 2]))return false;
            if (!isVowel(s[i]) && !isVowel(s[i + 1]) && !isVowel(s[i + 2]))return false;
        }
    }
    
    //cout << "here 2" << "\n";
    return true;
}

bool f3(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o') return false;
    }
    return true;
}

int main()
{
    cin >> st;
    while (st != "end") {
        
        if (f1(st) && f2(st) && f3(st)) cout << "<" << st << "> is acceptable." << "\n";
        else cout << "<" << st << "> is not acceptable." << "\n";
        cin >> st;
    }
}
