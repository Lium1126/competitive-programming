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
	ll n, m;
	cin >> n >> m;

	vector<set<ll>> s(n + 1);

	ll a, b;
	rep(i, m) {
		cin >> a >> b;
		s[a].insert(b);
		s[b].insert(a);
	}

	irep(i, n) {
		cout << s[i].size() << ' ';
		for (auto itr = s[i].begin();itr != s[i].end();itr++) {
			cout << *itr << ' ';
		}
		cout << endl;
	}

	return 0;
}