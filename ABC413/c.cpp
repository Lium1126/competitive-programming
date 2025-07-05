#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <deque>
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
	ll q;
	cin >> q;

	ll cmd, c, x, k;
	deque<P> dq;
	while(q--) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> c >> x;
			dq.push_back(P(c, x));
		} else {
			cin >> k;
			
			ll sum = 0;
			while (k > 0) {
				P tmp = dq.front();

				if (tmp.first <= k) {
					k -= tmp.first;
					sum += tmp.first * tmp.second;
					dq.pop_front();
				} else {
					tmp.first -= k;
					sum += k * tmp.second;
					dq.front() = tmp;
					k = 0;
				}
			}

			cout << sum << endl;
		}
	}

	return 0;
}