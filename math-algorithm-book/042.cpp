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
	ll n, ans = 0;
	cin >> n;

	vector<ll> p(n + 1, 0);
	for (ll i = 1;i <= n;i++) {
		for (ll j = i;j <= n;j += i) p[j]++;
		ans += i * p[i];
	}

	cout << ans << endl;
	
	return 0;
}