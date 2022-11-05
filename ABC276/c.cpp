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

bool isSame(vector<ll> a, vector<ll> b) {
	rep(i, a.size()) if (a[i] != b[i]) return false;
	return true;
}

int main() {
	ll n;
	cin >> n;

	vector<ll> v(n);
	set<ll> s;
	rep(i, n) {
		cin >> v[i];
		s.insert(i + 1);
	}

	vector<ll> ans;
	rep(i, n) {
		ll target = v[i];
		s.erase(target);
		vector<ll> tmp, tmp2;
		for (auto itr = s.begin();itr != s.end();itr++) tmp.push_back(*itr);
		for (ll j = i + 1;j < n;j++) tmp2.push_back(v[j]);

		if (!isSame(tmp, tmp2)) ans.push_back(v[i]);
		else {
			auto lb = s.lower_bound(target);
			lb--;
			ans.push_back(*lb);
			s.erase(*lb);
			s.insert(target);
			break;
		}
	}

	vector<ll> tmp;
	for (auto itr = s.begin();itr != s.end();itr++) tmp.push_back(*itr);
	for (ll i = tmp.size() - 1;i >= 0;i--) ans.push_back(tmp[i]);

	rep(i, ans.size()) cout << ans[i] << ' ';
	cout << endl;


	return 0;
}