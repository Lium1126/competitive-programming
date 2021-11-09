#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
	ll n;
	cin >> n;
	ll a, b;
	vector<ll> v[n];
	rep(i, n - 1)
	{
		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bool f = false;
	rep(i, n)
	{
		if (v[i].size() == n - 1)
			f = true;
	}
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}