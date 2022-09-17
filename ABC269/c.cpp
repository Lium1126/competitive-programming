#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

typedef pair<ll,ll> P;

int main() {
	string s;
	ll n;
	cin >> n;

	while (n != 0) s = s + (char)('0' + (n % 2)), n /= 2;
//	cout << s << endl;

	vector<string> v; v.push_back("0");
	rrep(i, s.length()) {
		if (s[i] == '0') rep(j, v.size()) v[j] = v[j] + '0';
		else {
			ll s = v.size();
			rep(j, s) v.push_back(v[j] + '1'), v[j] = v[j] + '0';
		}
	}

	vector<ll> ans(v.size());
	rep(i, v.size()) {
		string tmp = v[i];
		ll m = 0;
		rep(j, tmp.length()) m <<= 1, m += (tmp[j] - '0');
		ans[i] = m;
	}

	sort(ans.begin(), ans.end());
	rep(i, ans.size()) cout << ans[i] << endl;

	return 0;
}