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

int main() {
	ll n, p, q, r;
	cin >> n >> p >> q >> r;
	vector<ll> a(n), s(n + 1, 0);
	rep(i, n) {
		cin >> a[i];
		s[i + 1] = s[i] + a[i];
	}

	vector<vector<ll>> v(3, vector<ll>(n + 1, 0));
	// p
	ll left = 1, right = 1;
	while (right <= n) {
		if (s[right] - s[left - 1] == p) {
			v[0][left] = right;
			right++;
		}
		if (s[right] - s[left - 1] < p) right++;
		if (s[right] - s[left - 1] > p) {
			left++;
//			if (left == right) right++;
		}
	}

	// q
	left = 1, right = 1;
	while (right <= n) {
		if (s[right] - s[left - 1] == q) {
			v[1][left] = right;
			right++;
		}
		if (s[right] - s[left - 1] < q) right++;
		if (s[right] - s[left - 1] > q) {
			left++;
//			if (left == right) right++;
		}
	}

	// r
	left = 1, right = 1;
	while (right <= n) {
		if (s[right] - s[left - 1] == r) {
			v[2][left] = right;
			right++;
		}
		if (s[right] - s[left - 1] < r) right++;
		if (s[right] - s[left - 1] > r) {
			left++;
//			if (left == right) right++;
		}
	}
/*
	rep(i, 3) {
		irep(j, n) {
			cout << v[i][j] << '|';
		}
		cout << endl;
	}
*/
	irep(i, n) {
		if (v[0][i] != 0) {
			ll idx = v[0][i] + 1;
			if (v[1][idx] != 0) {
				ll idx2 = v[1][idx] + 1;
				if (v[2][idx2] != 0) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	cout << "No" << endl;

	return 0;
}