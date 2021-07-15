#include <iostream>
using namespace std;

int main() {
    int n, s, t;
    int w;
    int a;
    cin >> n >> s >> t;
    cin >> w;
    int ans = 0;
    if (s <= w && w <= t) ans++;
    for (int i = 1;i < n;i++) {
        cin >> a;
        w += a;
        if (s <= w && w <= t) ans++;
    }
    cout << ans << endl;
    return(0);
}
