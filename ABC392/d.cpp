#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
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
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	ll n;
	cin >> n;

	vector<ll> k(n);
	vector<unordered_multiset<ll>> v(n);
	vector<set<ll>> s(n);
	ll in;
	rep(i, n) {
		cin >> k[i];
		rep(j, k[i]) {
			cin >> in;
			v[i].insert(in);
			s[i].insert(in);
		}
	}

	double ans = 0.0;
	rep(i, n - 1) {
		for (ll j = i + 1;j < n;j++) {
			ll cnt = 0;
			for (auto itr = s[i].begin();itr != s[i].end();itr++) {
				cnt += v[j].count(*itr) * v[i].count(*itr);
			}
			ans = max(ans, (double)cnt / (double)(k[i] * k[j]));
		}
	}

	printf("%.12lf\n", ans);

	return 0;
}