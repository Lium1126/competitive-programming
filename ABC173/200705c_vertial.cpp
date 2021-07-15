#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0;i < n;i++)
using namespace std;
using ll = long long;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    char maze[10][10];
    rep(i, h) {
        rep(j, w) {
            cin >> maze[i][j];
        }
    }
    int ans = 0;

    rep(mr, (1 << h)) {
        rep(mc, (1 << w)) {
            int b = 0;
            rep(i, h) {
                rep(j, w) {
                    if (((mr >> i) & 1) == 0 && ((mc >> j) & 1) == 0 && maze[i][j] == '#') b++;
                }
            }
            if (b == k) ans++;
        }
    }

    cout << ans << endl;

    return(0);
}
