#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
using namespace atcoder;

int main() {
	ll n, k;
	cin >> n >> k;
	
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	if (n == 1) {
		cout << a[0] << endl;
		return 0;
	} else {
		fenwick_tree<ll> fw(n + 1);
		ll tmp = 1;

		for (ll cnt = k - 1;cnt < n;cnt++, tmp++) {
			if (cnt == k - 1) rep(i, k) fw.add(a[i], 1);
			else fw.add(a[cnt], 1);

			// k番目に大きい値は？
			// fw.sum(v) >= k となる最小の v を二分探索によって求める
			ll left = 1, right = n;
			while (right - left > 1) {
    			int mid = left + (right - left) / 2;
			    if (fw.sum(1, mid + 1) >= tmp) right = mid;
			    else left = mid;
			}

			if (fw.sum(1, left + 1) >= tmp) cout << left << endl; 
			else cout << right << endl;
		}
	}
	
	return 0;
}