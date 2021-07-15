#include <iostream>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0;i < n;i++)

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll cnt = 0;

    if (b >= c * d) cout << -1 << endl;
    else {
        ll sky = a, red = 0;
        while(1) {
            if (sky <= red) {
                break;
            }
            sky += b;
            red += c * d;
            cnt++;
        }
        cout << cnt << endl;
    }
    
    return 0;
}
