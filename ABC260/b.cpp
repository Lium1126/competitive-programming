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

typedef struct {
	ll m, e, s, n;
} Person;

bool cmp_m(const Person &a, const Person &b) {
	if (a.m != b.m) return a.m < b.m;
	return a.n > b.n;
}

bool cmp_e(const Person &a, const Person &b) {
	if (a.e != b.e) return a.e < b.e;
	return a.n > b.n;
}

bool cmp_s(const Person &a, const Person &b) {
	if (a.s != b.s) return a.s < b.s;
	return a.n > b.n;
}

int main() {
	ll n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<Person> v(n);
	vector<ll> a(n), b(n), ans;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n) {
		v[i].m = a[i]; v[i].e = b[i]; v[i].s = a[i] + b[i]; v[i].n = i + 1;
	}


	sort(v.begin(), v.end(), cmp_m);
	rep(i, x) {
		ans.push_back(v[v.size() - 1].n);
		v.pop_back();
	}

	sort(v.begin(), v.end(), cmp_e);
	rep(i, y) {
		ans.push_back(v[v.size() - 1].n);
		v.pop_back();
	}

	sort(v.begin(), v.end(), cmp_s);
	rep(i, z) {
		ans.push_back(v[v.size() - 1].n);
		v.pop_back();
	}

	sort(ans.begin(), ans.end());
	rep(i, ans.size()) cout << ans[i] << endl;

	return 0;
}