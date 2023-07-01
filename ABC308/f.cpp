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

bool fcomp(const P& a, const P& b) { 
	if (a.second != b.second) {
		return a.second > b.second;
	} else {
		return a.first > b.first;
	}
}

int main() {
	ll n, m;
	cin >> n >> m;

	vector<ll> p(n), l(m), d(m);
	rep(i, n) cin >> p[i];
	rep(i, m) cin >> l[i];
	rep(i, m) cin >> d[i];
	vector<P> c(m);
	rep(i, m) c[i] = P{l[i], d[i]};

	sort(p.begin(), p.end(), greater<ll>());
	sort(c.begin(), c.end(), fcomp);

	rep(i, n) cout << p[i] << endl;
	rep(i, m) cout << c[i].first << ' ' << c[i].second << endl;

	queue<ll> pque;
	queue<ll> bought;

	rep(i, n) pque.push(p[i]);

	rep(i, m) {
		P now = c[i];
		if (now.first > pque.front()) {
			// クーポン破棄
			continue;
		}
		bought.push(pque.front() - now.second);
		pque.pop();
	}
	while(!pque.empty()) { bought.push(pque.front()); pque.pop(); }

	ll ans = 0;
	while (!bought.empty()) {
//		cout << bought.front() << endl;
		ans += bought.front(); bought.pop();
	}
	cout << ans << endl;

	return 0;
}