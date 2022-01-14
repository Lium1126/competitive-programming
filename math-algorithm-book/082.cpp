#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define INF (1LL << 60);

typedef pair<ll, ll> P;

int main()
{
	ll n;
	cin >> n;

	ll l, r;
	vector<P> a;
	rep(i, n) {
		cin >> l >> r;
		a.push_back(P{l, r});
	}

	sort(a.begin(), a.end(), [](P &a, P &b)
		{ return a.second < b.second; });

	ll ans = 0;
	ll x = -INF;

	for (P p : a) {
		if (x <= p.first) {
			ans++;
			x = p.second;
		}
	}

	cout << ans << endl;

	return 0;
}