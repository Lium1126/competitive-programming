#include <iostream>
using namespace std;

int main() {
    int c[3] = {};
    string s;
    cin >> s;
    for (int i = 0;i < s.length();i++) c[s[i] - 'a']++;
    if (c[0] == 1 && c[1] == 1 && c[2] == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return(0);
}
