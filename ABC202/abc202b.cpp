#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0;i < s.length();i++) {
        if (s[i] == '6') s[i] = '9';
        else if (s[i] == '9') s[i] = '6';
    }
    for (int i = s.length() - 1;i >= 0;i--) {
        cout << s[i];
    }
    cout << endl;
    return(0);
}
