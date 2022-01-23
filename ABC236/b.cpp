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
	ll n;
	cin >> n;

	set<ll> st;
	map<ll, ll> mp;
	for (ll i = 1;i <= n;i++) {
		st.insert(i);
		mp[i] = 4;
	}

	ll a;
	rep(i, n * 4 - 1) {
		cin >> a;
		mp[a]--;
		if (mp[a] == 0) st.erase(a);
	}

	auto itr = st.begin();
	cout << *itr << endl;

	return 0;
}