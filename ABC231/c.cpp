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
	ll n, q;
	cin >> n >> q;

	ll input;
	vector<ll> a;
	rep(i, n)
	{
		cin >> input;
		a.push_back(input);
	}

	sort(a.begin(), a.end());

	rep(i, q)
	{
		cin >> input;
		auto itr = lower_bound(a.begin(), a.end(), input);
		if (itr == a.end())
			cout << 0 << endl;
		else if (itr == a.begin())
			cout << n << endl;
		else
			cout << a.end() - itr << endl;
	}

	return 0;
}