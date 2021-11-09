#include <iostream>
#include <string>
#include <set>

using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
	ll n;
	cin >> n;
	set<string> s;

	rep(i, n)
	{
		ll l, in;
		string str = "";

		cin >> l;
		rep(j, l)
		{
			cin >> in;
			str += (to_string(in) + ",");
		}
		s.insert(str);
	}

	cout << s.size() << endl;

	return 0;
}