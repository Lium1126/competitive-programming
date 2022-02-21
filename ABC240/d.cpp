#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef pair<ll, ll> P;

int main() {
	ll n;
	cin >> n;
	ll a;
	stack<P> s;
	ll ans = 0;
	rep(i, n) {
		cin >> a;
		if (s.empty() || s.top().first != a) {
			ans++;
			s.push(P{a, 1});
		} else {
			P tmp = s.top(); s.pop();
			ans -= tmp.second;
			if (tmp.second + 1 < a) {
				s.push(P{a, tmp.second + 1});
				ans += tmp.second + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}