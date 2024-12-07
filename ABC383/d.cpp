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

#define ll unsigned long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

ll multipow(ll p) {
	return p*p*p*p*p*p*p*p;
}

int main() {
	ll n;
	cin >> n;

	ll r = 1;
	while (r * r <= n) r++;
	r--;

	ll ans = 0;
	vector<bool> p(r + 5, true);
	p[0] = p[1] = false;
	vector<ll> pr;
	for (ll i = 2;i <= r;i++) {
		if (p[i]) {
			pr.push_back(i);
			for (ll j = 2 * i;j <= r;j += i) p[j] = false;
		}
	}

	rep(i, pr.size()) if (multipow(pr[i]) <= n) ans++;

	ll q_idx = pr.size() - 1;
	for (ll i = 0;i < pr.size() && i < q_idx;i++) {
		for (;pr[i]*pr[i]*pr[q_idx]*pr[q_idx] > n;q_idx--);
		// cout << pr[i] << ' ' << pr[q_idx] << endl;
		ans += i < q_idx ? q_idx - i : 0ULL;
	}

	cout << ans << endl;

	return 0;
}