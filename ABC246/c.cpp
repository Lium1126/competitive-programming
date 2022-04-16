#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n, k, x;
	cin >> n >> k >> x;
	vector<ll> a(n);
	ll input;
	rep(i, n) {
		cin >> input;
		if (input >= x && k > 0) {
			ll use = min(k, input / x);
			k -= use;
			input = input - x * use;
		}
		a[i] = input;
	}
	if (k > 0) {
		sort(a.begin(), a.end(), greater<ll>());
		ll cnt = 0;
		while (k > 0 && cnt < n) {
			a[cnt] = 0;
			k--;
			cnt++;
		}
	}
	ll ans = 0;
	rep(i, n) ans += a[i];
	cout << ans << endl;
	return 0;
}