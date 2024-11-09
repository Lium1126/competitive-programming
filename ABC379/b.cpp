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
	ll n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	bool flag = false;
	ll cnt = 0, ans = 0;
	for (char c : s) {
		if (c == 'O') {
			cnt++;
		} else {
			ans += cnt / k;
			cnt = 0;
		}
	}
	ans += cnt / k;

	cout << ans << endl;

	return 0;
}