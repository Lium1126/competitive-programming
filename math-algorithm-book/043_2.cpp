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
	ll n, m;
	cin >> n >> m;

	atcoder::dsu uf(n + 1);
	ll a, b;
	rep(i, m) {
		cin >> a >> b;
		if (!uf.same(a, b)) uf.merge(a, b);
	}

	set<ll> st;
	for (ll i = 1;i <= n;i++) {
		st.insert(uf.leader(i));
	}

	cout << (st.size() == 1 ? "The graph is connected." : "The graph is not connected.") << endl;

	return 0;
}