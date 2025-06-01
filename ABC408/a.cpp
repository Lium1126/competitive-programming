#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
typedef pair<ll, ll> P;

int main() {
	ll n, s;
	cin >> n >> s;

	vector<ll> t(n);
	rep(i, n) {
		cin >> t[i];
	}

	if (t[0] > s) {
		cout << "No" << endl;
		return 0;
	}

	for (ll i = 1; i < n; i++) {
		if (t[i] > t[i - 1] + s) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}
