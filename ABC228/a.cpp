#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
	ll s, t, x;
	cin >> s >> t >> x;

	bool f = false;

	for (ll i = s; i != t; i = (i + 1) % 24)
	{
		if (i == x)
			f = true;
	}

	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}