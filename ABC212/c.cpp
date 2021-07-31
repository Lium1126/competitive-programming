#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define rep(i,n) for (ll i = 0;i < n;i++)
#define INF (1 << 30)

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll> > a, b;
    pair<ll, ll> in;
    ll ans = INF;

    in.second = 0;
    rep (i, n) {
        cin >> in.first;
        a.push_back(in);       
    }
    in.second = 1;
    rep (i, m) {
        cin >> in.first;
        b.push_back(in);
    }

    a.insert(a.end(), b.begin(), b.end());
    stable_sort(a.begin(), a.end());

    rep(i, a.size()) {
        while (a[i].second == a[i + 1].second && i < a.size() - 1) i++;
        ans = min(ans, abs(a[i + 1].first - a[i].first));
    }

    cout << ans << endl;

    return 0;
}