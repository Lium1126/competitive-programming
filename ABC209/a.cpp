#include <iostream>
using namespace std;

#define ll long long
#define rep(i,n) for (ll i = 0;i < n;i++)

int main() {
    int a, b;
    cin >> a >> b;
    if (b >= a) cout << b - a + 1 << endl;
    else cout << 0 << endl;

    return 0;
}
