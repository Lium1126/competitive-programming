#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll n, s;
vector<ll> a(65);

bool solve(ll idx, ll now) {
	if (now > s) return false;
	if (now == s) return true;
	if (idx == n) return false;

	return solve(idx + 1, now) || solve(idx + 1, now + a[idx]);
}

int main() {
	cin >> n >> s;
	rep(i, n) cin >> a[i];

	cout << (solve(0, 0) ? "Yes" : "No") << endl;

	return 0;
}