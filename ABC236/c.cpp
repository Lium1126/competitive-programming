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

	map<string, bool> mp;
	vector<string> station;
	string s;
	rep(i, n) {
		cin >> s;
		mp[s] = false;
		station.push_back(s);
	}

	rep(i, m) {
		cin >> s;
		mp[s] = true;
	}

	rep(i, n) cout << (mp[station[i]] ? "Yes" : "No") << endl;

	return 0;
}