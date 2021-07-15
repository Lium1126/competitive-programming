#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    int d;
    cin >> d;
    int cnt  = 0;

    for (int i = l;i <= r;i++) {
        if (!(i % d)) cnt++;
    }

    cout << cnt << endl;

    return(0);
}
