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

	string s;
	cin >> s;

	if (n == 2) {
		if (s[0] == '1') cout << s[1] - '0' << endl;
		else cout << -1 << endl;
		return 0;
	}

	bool f = true;
	for (ll i = 1;i < n;i += 2) {
		if (s[i] != '1') f = false;
	}
	if (!f) {
		cout << -1 << endl;
		return 0;
	}

	ll ans = 0;
	vector<ll> a;
	for (ll i = 2;i < n;i += 2) 
	a.push_back(s[i] - '0');
	// for (ll out : a) cout << out << ' ';
	// cout << endl;

	ll one_num = 0;
	bool first = true;
	rrep(i, a.size()) {
		ans += one_num + 1;
		one_num = (one_num + 1) * a[i];
//		cout << one_num << endl;
	}


	if (s.length() % 2 == 1) {
		cout << ans + one_num << endl;
	} else {
		cout << ans + one_num + 1 << endl;
	}

	return 0;
}