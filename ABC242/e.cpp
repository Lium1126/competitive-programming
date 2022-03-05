#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)
#define MOD (998244353)

using namespace std;

int main() {
	ll t;
	cin >> t;
	rep(i, t) {
		ll n;
		string s;
		cin >> n >> s;
		if (n % 2 == 0) {
			if (s[n / 2 - 1] > s[n / 2]) swap(s[n / 2 - 1], s[n / 2]);
			string tmp = s.substr(0, n / 2);
			string r(tmp.rbegin(), tmp.rend());
			ll sum = 0;
			ll b = 1;
			for (char x : r) {
				sum = (sum + (b * (x - 'A') % MOD)) % MOD;
				b = (b * 26) % MOD;
			}
			sum = (sum + 1) % MOD;
			cout << sum << endl;
		} else {
			string tmp = s.substr(0, n / 2);
			string r(tmp.rbegin(), tmp.rend());
			ll sum = 0;
			ll b = 1;
			for (char x : r) {
				sum = (sum + (b * (x - 'A') % MOD)) % MOD;
				b = (b * 26) % MOD;
			}
			sum = (sum + 1) % MOD;
			cout << s[n / 2] << endl;
			sum = (sum * (s[n / 2] - 'A' + 1)) % MOD;
			cout << sum << endl;
		}
	}
	return 0;
}