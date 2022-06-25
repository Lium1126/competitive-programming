#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef pair<ll, ll> P;

int main() {
	ll n, w, ans = 0, child = 0;
	cin >> n;
	string s;
	cin >> s;
	vector<P> a(n);
	rep(i, n) {
		cin >> w;
		a[i] = make_pair(w, s[i] - '0');
	}

	sort(a.begin(), a.end());
	vector<ll> sum(n + 1, 0);
	for (ll i = 1;i <= n;i++) {
		sum[i] = sum[i - 1] + a[i - 1].second;
		if(a[i - 1].second == 0) child++;
	}

/*
	rep(i, n) {
		cout << "(" << a[i].first << ", " << a[i].second << ") ";
	}
	cout << endl;
*/
/*
	rep(i, n) cout << sum[i + 1] << ' ';
	cout << endl;
*/

	ans = n - child;
	for (ll i = 1;i <= n;i++) {
		if (i != n && a[i - 1].first == a[i].first) continue;
		ll wa = sum[i];
		ll wc = (n - i) - (sum[n] - sum[i]);
//		cout << i << ": wa = " << wa << ", wc = " << wc << endl;
		ans = max(ans, n - (wa + wc));
	}

	cout << ans << endl;

	return 0;
}