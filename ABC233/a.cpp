#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main()
{
	ll x, y;
	cin >> x >> y;
	y -= x;
	if (y <= 0)
		cout << 0 << endl;
	else if (y % 10 == 0)
		cout << y / 10 << endl;
	else
		cout << y / 10 + 1 << endl;
	return 0;
}