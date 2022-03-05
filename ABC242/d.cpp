#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

string s;

char solve(ll t, ll k) {
	if (t == 0) return s[k - 1];
	else {
		if (k % 2 == 0) {
			char prev = solve(t - 1, k / 2);
			if (prev == 'A') return 'C';
			else if (prev == 'B') return 'A';
			else return 'B';
		} else {
			char prev = solve(t - 1, (k + 1) / 2);
			if (prev == 'A') return 'B';
			else if (prev == 'B') return 'C';
			else return 'A';
		}
	}
}

int main() {
	cin >> s;
	ll q;
	cin >> q;
	ll t, k;
	rep(i, q) {
		cin >> t >> k;
		cout << solve(t, k) << endl;
	}
	return 0;
}