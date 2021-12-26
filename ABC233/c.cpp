#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

ll n, x;
vector<ll> sz;
vector<vector<ll>> vec;

ll solve(ll i, ll now)
{
	if (i == n - 1)
	{
		ll cnt = 0;
		rep(j, sz[i])
		{
			if (now * vec[i][j] == x)
				cnt++;
		}
		return cnt;
	}
	else
	{
		ll ret = 0;
		rep(j, sz[i])
		{
			if (now * vec[i][j] <= x)
			{
				ret += solve(i + 1, now * vec[i][j]);
			}
		}
		return ret;
	}
}

int main()
{
	cin >> n >> x;

	rep(i, n)
	{
		ll l;
		cin >> l;
		sz.push_back(l);
		vector<ll> tmp(l);
		rep(j, l) cin >> tmp[j];
		vec.push_back(tmp);
	}

	cout << solve(0, 1) << endl;

	return 0;
}