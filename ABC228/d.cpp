#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define N (2 << 19)

vector<ll> a(N);
set<ll> s;

int main()
{
	rep(i, N) {
		 a[i] = -1;
		 s.insert(i);
	}

	ll q;
	cin >> q;

	ll t, x;
	rep(i, q) {
		cin >> t >> x;
		if (t == 1) {
		    decltype(s)::iterator it = s.lower_bound(x % N);

			if (it == s.end())
				it = s.lower_bound(0);

			a[*it] = x;
			s.erase(*it);
		} else {
			cout << a[x % N] << endl;
		}
	}

	return 0;
}