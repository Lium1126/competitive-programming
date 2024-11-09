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
	ll q;
	cin >> q;

	vector<ll> v, p;
	v.push_back(0);

	irep(i, q) {
		ll x;
		cin >> x;
		switch (x)
		{
		case 1:
			p.push_back(i);
			v.push_back(v[v.size() - 1]);

			break;
		case 2:
			ll t;
			cin >> t;
			v.push_back(v[v.size() - 1] + t);
			break;
		case 3:
			ll h, ans = 0;
			cin >> h;

			v.push_back(v[v.size() - 1]);

			for (ll tmp : p) {
				// cout << v[i] - v[tmp] << ' ';
				if (v[i] - v[tmp] >= h) ans++;
			}
			// cout << endl;
			rep(j, ans) p.erase(p.begin());

			cout << ans << endl;
			break;
		}
	}
	return 0;
}