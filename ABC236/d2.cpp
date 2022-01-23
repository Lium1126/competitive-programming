#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 1;i <= n;i++)

using namespace std;

vector<vector<ll>> a(20, vector<ll>(20, -1));

typedef pair<ll, ll> P;

ll solve(vector<P> pairs, set<ll> p) {
	if (p.size() == 0) {
		ll ret;
		for (ll i = 0;i < pairs.size();i++) {
			if (i == 0) ret = a[pairs[i].first][pairs[i].second];
			else ret ^= a[pairs[i].first][pairs[i].second];
		}

		return ret;
	}

	ll ret = 0;
	vector<ll> tmp;
	for (ll x : p) tmp.push_back(x);

	for (ll i = 0;i < tmp.size() - 1;i++) {
		for (ll j = i + 1;j < tmp.size();j++) {
			pairs.push_back(make_pair(tmp[i], tmp[j]));
			p.erase(tmp[i]), p.erase(tmp[j]);
			ret = max(ret, solve(pairs, p));
			p.insert(tmp[i]), p.insert(tmp[j]);
			pairs.pop_back();
		}
	}
	
	return ret;
}

int main() {
	ll n;
	cin >> n;

	ll input;
	for (ll i = 1;i <= 2 * n - 1;i++) {
		for (ll j = i + 1;j <= 2 * n;j++) {
			cin >> input;
			a[i][j] = input;
			a[j][i] = input;
		}
	}

	set<ll> p;
	rep(i, 2 * n) p.insert(i);
	
	ll ans = 0;
	p.erase(1);
	for (ll i = 2;i <= 2 * n;i++) {
		vector<P> pairs;
		pairs.push_back(make_pair(1, i));
		p.erase(i);
		ans = max(ans, solve(pairs, p));
		p.insert(i);
		pairs.pop_back();
	}

	cout << ans << endl;

	return 0;
}