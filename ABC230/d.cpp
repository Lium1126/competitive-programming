#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define INF (1LL << 40)

typedef pair<ll, ll> P;

int main()
{
	ll n, d;
	cin >> n >> d;

	ll l, r;
	vector<P> walls;
	rep(i, n)
	{
		cin >> l >> r;
		walls.push_back(P{l, r});
	}

	sort(walls.begin(), walls.end(), [](P &a, P &b)
		 { return a.second < b.second; });

	ll ans = 0;
	ll x = -INF;

	for (P wall : walls)
	{
		if (x + d - 1 < wall.first)
		{
			ans++;
			x = wall.second;
		}
	}

	cout << ans << endl;

	return 0;
}