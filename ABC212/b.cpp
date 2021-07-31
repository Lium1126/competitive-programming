#include <iostream>
#include <stdlib.h>
using namespace std;

#define ll long long
#define rep(i,n) for (ll i = 0;i < n;i++)

int main() {
    string s;
    cin >> s;
    bool flag = true;
    if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3]) flag = false;
    else {
        bool flag2 = false;
        for (ll i = 0;i <= 2;i++) {
            if (s[i + 1] - '0' != (s[i] - '0' + 1) % 10) flag2 = true;
        }
        flag = flag2;
    } 

    if (flag) cout << "Strong" << endl;
    else cout << "Weak" << endl;

    return 0;
}