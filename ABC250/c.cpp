#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
int main() {
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n), idx(n + 1);
	rep(i, n) {
		a[i] = i + 1;
		idx[i + 1] = i;
	}

	ll x;
	rep(i, q) {
		cin >> x;
		ll t_i = idx[x];
		ll s_i = (t_i == n - 1 ? t_i - 1 : t_i + 1);
		ll s_n = a[s_i];

		ll tmp = a[t_i];
		a[t_i] = a[s_i];
		a[s_i] = tmp;

		idx[x] = s_i;
		idx[s_n] = t_i;

/*
		rep(i, n) {
			cout << a[i] << (i == n - 1 ? '\n' : ' ');
		}
*/
	}

	rep(i, n) {
		cout << a[i] << (i == n - 1 ? '\n' : ' ');
	}

	return 0;
}