#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <atcoder/dsu>

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main()
{
	ll n, m;
	cin >> n >> m;
	atcoder::dsu d(n);

	vector<set<ll>> v(n);
	set<ll> empty;
	rep(i, n) v[i] = empty;

	ll a, b;
	bool flg = true;
	rep(i, m)
	{
		cin >> a >> b;
		a--;
		b--;
		if (d.same(a, b))
			flg = false;

		d.merge(a, b);
		v[a].insert(b);
		v[b].insert(a);
	}

	rep(i, n)
	{
		if (v[i].size() >= 3)
			flg = false;
	}

	cout << (flg ? "Yes" : "No") << endl;

	return 0;
}