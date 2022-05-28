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
	ll q, n, x, c;
	cin >> q;
	map<ll, ll> m;
	set<ll> s, r;
	rep(i, q) {
		cin >> n;
		if (n == 1) {
			cin >> x;
			s.insert(x);
			r.insert(-x);
			m[x]++;
		}
		else if (n == 2) {
			cin >> x >> c;
			if(m[x] > c) m[x] -= c;
			else {
				m[x] = 0;
				s.erase(x);
				r.erase(-x);
			}
		}
		else {
			cout << (-1 * *(r.begin()) - *(s.begin())) << endl;
		}
	}
	return 0;
}