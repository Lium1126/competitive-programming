#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
typedef pair<ll, ll> P;

int main() {
	deque<P> que;
	ll q, t, x, c;
	cin >> q;
	rep(i, q) {
		cin >> t;
		if (t == 1) {
			cin >> x >> c;
			que.push_back(P{x, c});
		} else {
			cin >> c;
			ll cnt = 0, sum = 0;
			P tmp;
			while(cnt < c) {
				tmp = que.front(); que.pop_front();
				cnt += tmp.second;
				sum += tmp.first * tmp.second;
			}
			if (cnt > c) {
				sum -= tmp.first * (cnt - c);
				que.push_front(P{tmp.first, (cnt - c)});
			}
			cout << sum << endl;
		}
	}
	return 0;
}