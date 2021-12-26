#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <atcoder/all>
#include <algorithm>

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

typedef pair<ll, ll> P;

int main()
{
	ll n, k;
	cin >> n >> k;

	ll ans = 0;
	vector<ll> a(n), s(n + 1);
	map<ll, vector<ll>> apper;
	ll zero = 0;
	s[0] = 0;
	apper[0].push_back(0);
	rep(i, n)
	{
		cin >> a[i];
		if (a[i] == 0)
			zero++;
		s[i + 1] = s[i] + a[i];
		apper[s[i + 1]].push_back(i + 1);
	}

	if (zero == n)
	{
		cout << (n * (n + 1)) / 2 << endl;
	}
	else
	{
		for (ll i = n; i > 0; i--)
		{
			ll target = s[i] - k;
			if (apper[target].empty())
			{
				//			cout << target << ": continue" << endl;
				continue;
			}
			else
			{
				auto tmp = lower_bound(apper[target].begin(), apper[target].end(), i);
				auto head = apper[target].begin();
				ll num = tmp - head;
				ans += num;

				//			cout << target << ": " << (tmp - head) << endl;
			}
		}

		cout << ans << endl;
	}
	return 0;
}