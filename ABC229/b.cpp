#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
	ll a, b;
	cin >> a >> b;
	bool flag = true;

	while (a != 0 && b != 0 && flag)
	{
		ll tmpa = a % 10, tmpb = b % 10;
		if (tmpa + tmpb >= 10)
			flag = false;
		a /= 10;
		b /= 10;
	}

	cout << (flag ? "Easy" : "Hard") << endl;

	return 0;
}