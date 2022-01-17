#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll rotate(ll x) {
	ll first = x % 10;
	string s = to_string(x / 10);
	s = (char)(first + '0') + s;
	return stoll(s);
}

int main() {
	ll a, n;
	cin >> a >> n;

	ll m = 1;
	while (m <= n) m *= 10;

	vector<ll> visited(m, -1);
	visited[1] = 0;
	queue<ll> que;
	que.push(1);

	while(!que.empty()) {
		ll now = que.front(); que.pop();
		
		ll tmp = a * now;
		if (tmp < m && visited[tmp] == -1) {
			que.push(tmp);
			visited[tmp] = visited[now] + 1;
		}

		if (now >= 10 && now % 10 != 0) {
			tmp = rotate(now);
			if (tmp < m && visited[tmp] == -1) {
				que.push(tmp);
				visited[tmp] = visited[now] + 1;
			}
		}
	}

	cout << visited[n] << endl;

	return 0;
}