#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef pair<ll, ll> P;

int main() {
	ll n;
	cin >> n;

	vector<P> fact;

	for (ll i = 2;i * i <= n;i++) {
		if (n % i != 0) continue;
		ll ex = 0;

		while(n % i == 0) ex++, n /= i;
		fact.push_back(P{i, ex});
	}
	if (n != 1) fact.push_back(P{n, 1});

	rep(i, fact.size()) {
		rep(j, fact[i].second) {
			cout << fact[i].first << (i == fact.size() - 1 && j == fact[i].second - 1 ? '\n' : ' ');
		}
	}

	return 0;
}