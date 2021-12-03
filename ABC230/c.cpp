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
	ll n, a, b;
	cin >> n >> a >> b;

	ll p, q, r, s;
	cin >> p >> q >> r >> s;

	for (ll i = p; i <= q; i++)
	{
		for (ll j = r; j <= s; j++)
		{
			ll ky = i - a;
			ll kx = j - b;
			ll kx2 = b - j;
			if (max(1 - a, 1 - b) <= ky && ky <= min(n - a, n - b) && max(1 - a, 1 - b) <= kx && kx <= min(n - a, n - b) && ky == kx)
			{
				cout << "#";
			}
			else if (max(1 - a, b - n) <= ky && ky <= min(n - a, b - 1) && max(1 - a, b - n) <= kx2 && kx2 <= min(n - a, b - 1) && abs(ky) == abs(kx2))
			{
				cout << "#";
			}
			else
			{
				cout << ".";
			}
		}
		cout << endl;
	}

	return 0;
}