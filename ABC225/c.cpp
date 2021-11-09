#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

vector<vector<ll> > v;

int main()
{
	ll n, m;
	cin >> n >> m;
	ll a;
	bool f = true;

	rep(i, n)
	{
		vector<ll> tmp;
		rep(j, m)
		{
			cin >> a;
			tmp.push_back(a);
		}
		v.push_back(tmp);
	}

	rep(i, n)
	{
		rep(j, m)
		{
			if (j == 0) {
				if (i != 0)
				{
				if (v[i][j] != v[i - 1][j] + 7)
					f = false;
				}
			}
			else
			{
				ll a = v[i][j] % 7;
				if (a == 0)
					a = 7;
				ll b = v[i][j - 1] % 7;
				if (b == 0)
					b = 7;
				if (v[i][j] != v[i][j - 1] + 1 || a <= b) {
					f = false;
				}
			}
		}
	}

	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}