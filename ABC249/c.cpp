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
	ll n, k;
	cin >> n >> k;

	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}

	ll ans = 0;
	rep(i, (1 << n)) {
		vector<ll> v(26, 0);
		ll mask = 1;
		rep(j, n) {
			if (mask & i) {
				for (char c : s[j]) v[c - 'a']++;
			}
			mask <<= 1;
		}

/*
		cout << "------------" << endl;
		rep(j, 26) printf("%c: %d\n", 'a' + j, v[j]);
		cout << "------------" << endl;
*/
		
		ll cnt = 0;
		rep(j, 26) if (v[j] == k) cnt++;
		ans = max(ans, cnt);
	}

	cout << ans << endl;

	return 0;
}