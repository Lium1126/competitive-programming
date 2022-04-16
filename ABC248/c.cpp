#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
using mint = atcoder::modint998244353;

ll n, m, k;

mint solve(ll sum, ll cnt) {
	if (cnt == n) return (sum <= k ? 1 : 0);
	mint rec = 0;
	for (ll i = 1;i <= m;i++) {
		if (sum + i <= k) rec += solve(sum + i, cnt + 1);
	}
	return rec;
}

int main() {
	cin >> n >> m >> k;
	
	cout << solve(0, 0).val() << endl;

	return 0;
}