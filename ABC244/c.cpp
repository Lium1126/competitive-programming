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
	ll n, enemy;
	cin >> n;
	set<ll> s;
	rep(i, 2 * n + 1) s.insert(i + 1);
	do {
		cout << *s.begin() << endl << flush;
		s.erase(s.begin());
		if (s.empty()) break;
		cin >> enemy;
		s.erase(enemy);
	} while (!s.empty());
	return 0;
}