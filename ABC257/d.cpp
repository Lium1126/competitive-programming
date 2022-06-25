#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <atcoder/all>
#include <queue>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef pair<ll, ll> P;

ll n;
vector<P> d(205);
vector<ll> p(205);

ll dist(P a, P b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	ll x, y, Power;
	cin >> n;

	for (ll i = 1;i <= n;i++) {
		cin >> x >> y >> Power;
		d[i] = make_pair(x, y);
		p[i] = Power;
	}

	ll l = 1, r = 1000000000LL;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;

		ll s = 0;
		for (ll i = 1;i <= n;i++) {
			queue<ll> que;
			vector<bool> visited(n + 1, false);
			que.push(i);
			ll sum = 0;
			while(!que.empty()) {
				ll now = que.front(); que.pop();
				sum++;
				visited[now] = true;
				for (ll j = 1;j <= n;j++) {
					if (now == j) continue;
					if (p[now] * mid >= dist(d[now], d[j]) && !visited[j]) que.push(j);
				}
			}
			s = max(s, sum);
		}

		if (s == n) r = mid;
		else l = mid;
    }

	cout << r << endl;

	return 0;
}