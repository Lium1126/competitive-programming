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

	ll a;
	map<ll, ll> mp;
	rep(i, n) {
		cin >> a;
		mp[a]++;
	}

	cout << mp[100] * mp[400] + mp[200] * mp[300] << endl;

	return 0;
}