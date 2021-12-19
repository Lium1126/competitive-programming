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
	ll n, m;
	cin >> n >> m;

	vector<set<ll>> a(n), b(n);
	ll A, B;
	rep(i, m)
	{
		cin >> A >> B;
		A--;
		B--;
		a[A].insert(B);
		a[B].insert(A);
	}

	rep(i, m)
	{
		cin >> A >> B;
		A--;
		B--;
		b[A].insert(B);
		b[B].insert(A);
	}

	vector<ll> idx;
	rep(i, n) idx.push_back(i);

	bool flag = false;
	do
	{
		bool f = true;
		rep(i, n)
		{
			rep(j, n)
			{
				if (a[i].find(j) != a[i].end())
				{
					// aでiとjが連結
					if (b[idx[i]].find(idx[j]) == b[idx[i]].end())
					{
						f = false;
					}
				}
				else
				{
					// aでiとjが非連結
					if (b[idx[i]].find(idx[j]) != b[idx[i]].end())
					{
						f = false;
					}
				}
			}
		}

		if (f)
			flag = true;
	} while (next_permutation(idx.begin(), idx.end()));

	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}