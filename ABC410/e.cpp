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
typedef pair<P, ll> PP;

vector<P> battle(3005);
ll n, h, m;

int main() {
	cin >> n >> h >> m;

	rep(i, n) {
		ll a, b;
		cin >> a >> b;
		battle[i] = P{a, b};
	}

	vector<vector<ll>> dp(h + 1, vector<ll>(m + 1, -1));
	dp[h][m] = 0;
	set<pair<int, int>> cur, nxt;
	cur.insert({h, m});
	ll ans = 0;
	rep(i, n) {
		nxt.clear();
		vector<vector<ll>> ndp(h + 1, vector<ll>(m + 1, -1));
		for (P now : cur) {
			ll hp = now.first, mp = now.second;
			if (dp[hp][mp] == -1) continue;
			bool flag = false;

			if (hp >= battle[i].first) {
				int nhp = hp - battle[i].first, nmp = mp;
				if (ndp[nhp][nmp] < dp[hp][mp] + 1) {
					ndp[nhp][nmp] = dp[hp][mp] + 1;
					nxt.insert({nhp, nmp});
				}
				flag = true;
			}

			if (mp >= battle[i].second) {
				int nhp = hp, nmp = mp - battle[i].second;
				if (ndp[nhp][nmp] < dp[hp][mp] + 1) {
					ndp[nhp][nmp] = dp[hp][mp] + 1;
					nxt.insert({nhp, nmp});
				}
				flag = true;
			}

			if (!flag) ans = max(ans, dp[hp][mp]);
		}
		
		dp.swap(ndp);
		cur.swap(nxt);
	}

	rep(i, h + 1) rep(j, m + 1) ans = max(ans, dp[i][j]);
	cout << ans << endl;
	
	return 0;
}