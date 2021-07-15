#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    int n;
    cin >> n;
    ll in;
    ll now;
    ll ans = 0;
    for (int i = 0;i < n;i++) {
        cin >> in;

        if (i == 0) {
            now = in;
        } else {
            if (in <= now) ans += (now - in);
            else now = in;
        }
    }

    cout << ans << endl;

    return(0);
}
