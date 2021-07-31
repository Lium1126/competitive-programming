#include <iostream>
using namespace std;

#define ll long long
#define rep(i,n) for (ll i = 0;i < n;i++)

int main() {
    ll a, b;
    cin >> a >> b;
    if (a == 0 && b > 0) cout << "Silver" << endl;
    else if (a > 0 && b == 0) cout << "Gold" << endl;
    else cout << "Alloy" << endl;
    return 0;
}