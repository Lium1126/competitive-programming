#include <iostream>
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int s, t;
    cin >> s >> t;
    int ans = s * a + t * b;
    if (s + t >= k) ans -= c * (s + t);
    cout << ans << endl;
    return(0);
}
