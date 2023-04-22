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
	ll n;
	cin >> n;
	ll resp;

	if (n == 2) {
		cout << "! 1" << endl;
		return 0;
	} else {
		ll l = -1, r = n;
		while (r - l > 1) {
			ll mid = l + (r - l) / 2;
			cout << "? " << mid+1 << endl;
			flush(cout);

			cin >> resp;
			if (resp == 0) l = mid;
			else r = mid;
		}
		cout << "! " << min(l+1, r+1) << endl;
	}

	return 0;
}