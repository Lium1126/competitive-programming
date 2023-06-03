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

int main() {
	ll w, h;
	cin >> w >> h;

	ll n;
	cin >> n;

	vector<P> v(n);
	rep(i, n) cin >> v[i].first >> v[i].second;

	ll A, B, in;
	cin >> A;
	vector<ll> a;
	rep(i, A) {
		cin >> in;
		a.push_back(in);
	}
	a.push_back(w);
	cin >> B;
	vector<ll> b;
	rep(i, B) {
		cin >> in;
		b.push_back(in);
	}
	b.push_back(h);

	vector<P> st;
	set<P> st_st;
	rep(cnt, n) {
		P p = v[cnt];
		ll x = p.first, y = p.second;
		ll xl = lower_bound(a.begin(), a.end(), x) - a.begin();
		ll yl = lower_bound(b.begin(), b.end(), y) - b.begin();

		st.push_back(P{xl, yl});
		st_st.insert(P{xl, yl});
	}

	sort(st.begin(), st.end());

    vector<pair<P, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && st[l] == st[r]; r++) {};
        ret.push_back({st[l], r - l});
        l = r;
    }

	ll MIN = __LONG_LONG_MAX__, MAX = 0;
	rep(i, ret.size()) {
		if (MIN > ret[i].second) MIN = ret[i].second;
		if (MAX < ret[i].second) MAX = ret[i].second;
	}

	if (st_st.size() != (A + 1) * (B + 1)) MIN = 0;

	cout << MIN << ' ' << MAX << endl;

	return 0;
}