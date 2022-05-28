#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef pair<ll, ll> P;

int main() {
	ll h, w;
	cin >> h >> w;
	vector<P> p;
	string s;

	for (ll i = 1;i <= h;i++) {
		cin >> s;
		for (ll j = 1;j <= s.length();j++) {
			if (s[j - 1] == 'o') p.push_back(make_pair(i, j));
		}
	}

	cout << abs(p[0].first - p[1].first) + abs(p[0].second - p[1].second) << endl;

	return 0;
}