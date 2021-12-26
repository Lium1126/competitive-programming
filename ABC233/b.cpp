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
	ll l, r;
	string s;

	cin >> l >> r;
	cin >> s;

	l--;
	r--;

	rep(i, s.length())
	{
		if (l <= i && i <= r)
			cout << s[r - (i - l)];
		else
			cout << s[i];
	}
	cout << endl;

	return 0;
}