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
	ll m;
	cin >> m;

	vector<ll> d(m + 1);
	ll sum = 0;
	irep(i, m) {
		cin >> d[i];
		sum += d[i];
	}

	ll day = 0;
	ll middle = sum / 2 + 1;
	bool f = true;
	ll ans_month, ans_day;
	irep(i, m) {
		if (day + d[i] >= middle && f) {
			ans_month = i;
			ans_day = middle - day;
			f = false;
		}
		day += d[i];
	}

	cout << ans_month << ' ' << ans_day << endl;

	return 0;
}