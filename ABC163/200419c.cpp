#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll n;
    ll input;
    ll a[200001] = {};

    cin >> n;
    for (ll i = 2;i <= n;i++) {
        cin >> input;
        a[input]++;
    }

    for (ll i = 1;i <= n;i++) {
        cout << a[i] << endl;
    }

    return 0;
}
