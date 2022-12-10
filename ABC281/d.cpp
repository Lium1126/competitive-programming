#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

int main() {
	ll n, k, d;
	cin >> n >> k >> d;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	vector<vector<ll>> dp(n + 5, vector<ll>(k + 5, 0));
	set<ll> s;
	rep(i, n) {
		rep(j, k - 1) {
			if (j == k - 2) {
				ll tmp = dp[i][k] + a[i];
				if (tmp % d == 0) s.insert(tmp);
			} else {
				dp[i + 1][k] = dp[i][k];
				dp[i + 1][k + 1] = dp[i][k] + a[i];
			}
		}
	}

	for (auto itr = s.begin();itr != s.end();itr++) cout << *itr << ' ';
	cout << endl;

	if (s.size() == 0) cout << "-1" << endl;
	else {
		auto itr = s.end();
		itr--;
		cout << *itr << endl;
	}

	return 0;
}