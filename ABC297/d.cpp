#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

int main() {
	ll ans = 0;
	ll a, b;
	cin >> a >> b;

	if (a == b) {
		cout << 0 << endl;
		return 0;
	}

	while (a != b) {
		if (a > b) {
			if (a % b == 0) {
				ans += a / b - 1;
				a = b;
			}
			else {
				ans += a / b;
				a = a % b;
			}
		}
		else {
			if (b % a == 0) {
				ans += b / a - 1;
				b = a;
			}
			else {
				ans += b / a;
				b = b % a;
			}
		}
	}

	cout << ans << endl;

	return 0;
}