#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

vector<ll> t(200005);
vector<ll> k(200005);
vector<vector<ll> > a;
vector<bool> can(200005);
ll n;

ll solve(ll x)
{
	if (can[x]) return 0;
	if (k[x] == 0)
	{
		can[x] = true;
		return t[x];
	}

	ll rec = 0;
	rep(i, k[x])
	{
		if (!can[a[x][i] - 1])
		{
			rec += solve(a[x][i] - 1);
		}
	}
	can[x] = true;
	rec += t[x];
	return rec;
}

int main()
{
	cin >> n;

	rep(i, 200005) can[i] = false;

	rep(i, n)
	{
		cin >> t[i];
		cin >> k[i];
		vector<ll> tmp;
		ll in;
		rep(j, k[i])
		{
			cin >> in;
			tmp.push_back(in);
		}
		a.push_back(tmp);
	}

	cout << solve(n - 1) << endl;

	return 0;
}