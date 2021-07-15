#include <iostream>
#include <set>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

int main() {
    ll n;
    cin >> n;
    ll temp;
    bool flag = true;
    int a[1005] = {};
    rep(i, n) {
        cin >> temp;
        if (a[temp] == 1) flag = false;
        a[temp] = 1;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return(0);
}
