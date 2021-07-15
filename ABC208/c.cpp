#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define rep(i, n) for (long long i = 0;i < n;i++)
#define ll long long

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> input;
    vector<ll> number;
    map<ll, ll> m;
    ll temp;
    rep(i, n) {
        cin >> temp;
        input.push_back(temp);
        number.push_back(temp);
        m[temp] = k / n;
    }

    k %= n;

    sort(input.begin(), input.end());

    rep (i, k) {
        m[input[i]]++;
    }

    rep(i, n) cout << m[number[i]] << endl;

    return 0;
}
