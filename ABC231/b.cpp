#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main()
{
	ll n;
	cin >> n;

	string input;
	map<string, ll> m;
	rep(i, n)
	{
		cin >> input;
		m[input]++;
	}

	auto itr = m.begin();
	ll mx = m[itr->first];
	string ans = itr->first;
	while (itr != m.end())
	{
		if (mx < itr->second)
		{
			ans = itr->first;
			mx = itr->second;
		}
		itr++;
	}

	cout << ans << endl;

	return 0;
}