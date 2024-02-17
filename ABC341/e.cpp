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

S op(S a, S b){ return a != b ? 1 : 0; }
S e(){ return 1; }
S mapping(F f, S x){ return f ^ 1; }
F composition(F f, F g){ return f ^ 1; }
F id(){ return 0; }

int main() {
	ll n, q;
	cin >> n >> q;

	string s;
	cin >> s;

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
	for (int i;i < n;i++) cout << seg.get(i) << ' ';
	cout << endl;

	for (int i;i < n;i++) {
		S tmp = s[i] - '0';
		seg.set(i, tmp);
	}

	for (int i;i < n;i++) cout << seg.get(i) << ' ';
	cout << endl;

	ll x, l, r;
	while (q--) {
		cin >> x >> l >> r;
		if (x == 1) {
			l--, r--;
			seg.apply(l, r);
		} else {
			continue;
		}

		for (int i;i < n;i++) cout << seg.get(i) << ' ';
		cout << endl;
	}


	return 0;
}