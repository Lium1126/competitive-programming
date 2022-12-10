#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

int main() {
	ll n, t, total = 0;
	cin >> n >> t;

	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
		total += a[i];
	}

	t %= total;

	ll i = 0;
	while (1) {
		if (t <= a[i]) {
			cout << i + 1 << ' ' << t << endl;
			break;
		}
		t -= a[i];
		i++;
	}
	
	return 0;
}