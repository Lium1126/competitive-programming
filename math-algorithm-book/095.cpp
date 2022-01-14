#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 1;i <= n;i++)

using namespace std;

typedef pair<ll, ll> P;

int main() {
	ll n;
	cin >> n;

	ll c, p;
	vector<P> data(n + 1);
	vector<vector<ll>> sum(3, vector<ll>(n + 1, 0));
	rep(i, n) {
		cin >> c >> p;
		data[i] = make_pair(c, p);
	}

	rep(i, n) {
		rep(j, 2) sum[j][i] = sum[j][i - 1];
		sum[data[i].first][i] += data[i].second;
	}

	ll q, l, r;
	cin >> q;
	rep(cnt, q) {
		cin >> l >> r;
		ll a = sum[1][r] - sum[1][l - 1];
		ll b = sum[2][r] - sum[2][l - 1];
		cout << a << ' ' << b << endl;
	}

	return 0;
}