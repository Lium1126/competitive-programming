#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < n;i++)
using namespace std;
using ll = long long;

int main() {
    map<string, int> m;
    int n;
    cin >> n;
    string s;
    rep(i, n) {
        cin >> s;
        m[s]++;
    }

    for (string s : {"AC", "WA", "TLE", "RE"}) {
        cout << s << " x " << m[s] << endl;;
    }
    
    return(0);
}
