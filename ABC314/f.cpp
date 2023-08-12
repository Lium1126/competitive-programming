#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

using mint = static_modint<998244353>;

int main() {
	ll n;
	cin >> n;
	ll a, b;
	
	dsu uf(n);
	vector<ll> point(n);
	rep(i, n) point[i] = i;
	vector<mint> win(n, 0);
	rep(cnt, n - 1) {
		cin >> a >> b;
		a--, b--;

		ll asize = uf.size(a);
		ll bsize = uf.size(b);

		mint awin = (mint(asize) / mint(asize + bsize));
		mint bwin = (mint(bsize) / mint(asize + bsize));

		ll al = uf.leader(a);
		ll bl = uf.leader(b);

		
	}

	return 0;
}