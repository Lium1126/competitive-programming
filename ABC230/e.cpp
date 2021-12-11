#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <math.h>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
	ll n;
	cin >> n;

	ll ans = 0;
	ll m = 1;
	while (m <= n / 2)
	{
		// m.xxxを探す
		ll left = n / m;
		ll right = ceil((double)n / (double)(m + 1));
		cout << m << ": " << right << ' ' << left << endl;
		ans += m * (left - (right - 1));

		if (left == right)
			m = n / (right - 1);
		if (n % right == 0)
			m = n / right;
		else
			m = n / (right - 1);
	}

	cout << ans + n << endl;

	return 0;
}