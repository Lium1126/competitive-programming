#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
typedef pair<ll, ll> P;

int main() {
	set<P> st;
	rep(h, 24) {
		rep(m, 60) {
			ll ht = (h / 10) * 10 + (m / 10);
			ll mt = (h % 10) * 10 + (m % 10);

			if (0 <= ht && ht <= 23 && 0 <= mt && mt <= 59) st.insert(make_pair(h, m));
		}
	}

	ll h, m;
	cin >> h >> m;
	P in = make_pair(h, m);
	decltype(st)::iterator itr = st.lower_bound(in);

	if (itr == st.end()) {
		itr = st.begin();
	}
	cout << (*itr).first << ' ' << (*itr).second << endl;

	return 0;
}