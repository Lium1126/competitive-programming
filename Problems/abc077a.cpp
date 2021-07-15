#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    bool flag = true;
    for (int i = 0;i < s.length() && flag;i++) {
        if (s[i] != t[t.length() - i - 1]) flag  = false;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return(0);
}
