#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x, n;
    set<int> p;
    int ans = -1;

    cin >> x >> n;
    for (int i = 0;i < n;i++) {
        int input;
        cin >> input;
        p.insert(input);
    }

    for (int i = 0;i < 100;i++) {
        int up = x + i;
        int down = x - i;
        if (p.find(up) == p.end()) {
            ans = up;
        }
        if (p.find(down) == p.end()) {
            ans = down;
        }
        if (ans != -1) break;
    }

    cout << ans << endl;

    return 0;
}
