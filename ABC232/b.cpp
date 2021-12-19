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
	string s, t;
	cin >> s >> t;

	bool flag = false;
	for (ll i = 1; i <= 26 && !flag; i++)
	{
		rep(j, s.length())
		{
			s[j] = (((s[j] - 'a') + 1) % 26 + 'a');
		}

		if (s == t)
			flag = true;
	}

	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}