#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
	ll n;
	vector<ll> v;
	ll in;
	set<ll> s;

	cin >> n;
	rep(i, n)
	{
		cin >> in;
		v.push_back(in);
	}

	for (ll a = 1; a <= 1000; a++)
	{
		for (ll b = 1; b <= 1000; b++)
		{
			s.insert(4 * a * b + 3 * a + 3 * b);
		}
	}

	ll ans = 0;
	rep(i, n)
	{
		if (s.find(v[i]) == s.end())
		{
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}