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

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
	ll n;
	cin >> n;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
	rep(i, n) {
		ll give = n - (i + 1);
		ll tmp = min(seg.get(i), give);

		seg.set(i, seg.get(i) - tmp);
		if (tmp > 0) {
			seg.apply(i+1, i + tmp + 1, {1LL});
		}

		// cout << i << ": ";
		// rep(i, n) cout << seg.get(i) << ' ';
		// cout << endl;
	}

	rep(i, n) {
		cout << seg.get(i) << ' ';
	}
	cout << endl;

	return 0;
}