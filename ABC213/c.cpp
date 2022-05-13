#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>
#include <algorithm>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
typedef pair<ll, ll> P;

int main() {
	ll h, w, n;
	cin >> h >> w >> n;

	vector<ll> x(n), y(n), ux(n), uy(n);
	rep(i, n) {
		cin >> x[i] >> y[i];
		ux[i] = x[i], uy[i] = y[i];
	}

	sort(ux.begin(), ux.end());
	sort(uy.begin(), uy.end());

	ux.erase(unique(ux.begin(), ux.end()), ux.end());
	uy.erase(unique(uy.begin(), uy.end()), uy.end());

	rep(i, n) {
		cout << (lower_bound(ux.begin(), ux.end(), x[i]) - ux.begin()) + 1 << ' ' << (lower_bound(uy.begin(), uy.end(), y[i]) - uy.begin()) + 1 << endl;
	}

	return 0;
}