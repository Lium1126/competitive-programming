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
	ll n, s, ans = 0;
	cin >> n >> s;

	rep(i, n) {
		rep(j, n) {
			if (i + j + 2 <= s) ans++;
		}
	}

	cout << ans << endl;
	
	return 0;
}