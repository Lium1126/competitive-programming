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
	ll n;
	cin >> n;
	ll l, r;
	vector<P> vec(n), ans;

	rep(i, n) {
		cin >> l >> r;
		vec[i] = make_pair(l, r);
	}

	sort(vec.begin(), vec.end());
	ll nowl = vec[0].first;
	ll mr = vec[0].second;
	bool f = false;

	for (ll i = 1;i < n;i++) {
		if (mr < vec[i].first) {
			ans.push_back(make_pair(nowl, mr));
			f = true;
			nowl = vec[i].first;
			mr = vec[i].second;
		}
		else {
			f = false;
			mr = max(mr, vec[i].second);
		}
	}

	ans.push_back(make_pair(nowl, mr));

	sort(ans.begin(), ans.end());

	rep(i, ans.size()) cout << ans[i].first << ' ' << ans[i].second << endl;

	return 0;
}