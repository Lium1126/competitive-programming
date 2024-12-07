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

	vector<ll> prp;
	for (ll tmp : pr) {
		ans += multipow(tmp) <= n ? 1 : 0;
		prp.push_back(tmp * tmp);
	}

	rep(i, prp.size()) {
		ll p = prp[i];
		    int left = -1;
			int right = (int)prp.size();
			
			while (right - left > 1) {
				int mid = left + (right - left) / 2;

				if (prp[i]*prp[mid] > n) right = mid;
				else left = mid;
			}
			
			if (i <= left && left != -1) ans += left - i;
	}

	cout << ans << endl;

	return 0;
}