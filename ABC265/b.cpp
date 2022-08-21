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

typedef pair<ll, ll> P;

int main() {
	ll n, m, t, x, y;
	cin >> n >> m >> t;

	vector<P> v(n + 1, make_pair(0, 0));

	irep(i, n - 1) {
		cin >> v[i].first;
	}
	rep(i, m) {
		cin >> x >> y;
		v[x].second = y;
	}

	ll now = 1;
	while (1) {
		t += v[now].second;
		if (t > v[now].first) {
			t -= v[now].first;
			now++;
			if (now == n) {
				cout << "Yes" << endl;
				return 0;
			}
		} else {
			cout << "No" << endl;
			return 0;
		}
	}

	return 0;
}