#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0;i < s.length();i++) {
        if (s[i] == '1') s[i] = '9';
        else if (s[i] == '9') s[i] = '1';
    }
    cout << s << endl;
    return(0);
}
