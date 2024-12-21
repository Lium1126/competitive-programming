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
	vector<ll> a(3);
	ll sum = 0;
	rep(i, 3) {
		cin >> a[i];
		sum += a[i];
	}
	rep(i, 3) {
		if (sum - a[i] == a[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	if (a[0] == a[1] && a[1] == a[2]) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}