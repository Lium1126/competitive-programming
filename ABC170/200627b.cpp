#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x, y;
    cin >> x >> y;
    bool flag = false;

    for (int c = 0;c <= x;c++) {
        int t = (x - c);
        if (2 * c + 4 * t == y) flag = true;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
