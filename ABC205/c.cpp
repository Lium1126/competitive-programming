#include <iostream>
using namespace std;

#define rep(i, n) for (int i = 0;i < n;i++)
#define ll long long

bool J(ll a, ll b) {
    // a^b >= 0?
    if (a >= 0) return true;
    else if(b % 2 == 0) return true;
    else return false;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (abs(a) == abs(b)) {
        if (a * b >= 0) cout << "=" << endl;
        else {
            if (c % 2 == 0) cout << "=" << endl;
            else if(a < 0) cout << "<" << endl;
            else cout << ">" << endl;
        }
    }
    else if (a >= 0 && b >= 0) {
        if (a < b) cout << "<" << endl;
        else cout << ">" << endl;
    } else {
        bool ja = J(a, c);
        bool jb = J(b, c);
        if (ja && jb) { // 両方正
            if (abs(a) < abs(b)) cout << "<" << endl;
            else cout << ">" << endl;
        }
        else if (ja && !jb) {
            cout << ">" << endl;
        }
        else if (!ja && jb) {
            cout << "<" << endl;
        }
        else {
            if (abs(a) < abs(b)) cout << ">" << endl;
            else cout << ">" << endl;
        }
    }
    return(0);
}
