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
	ll n, k;
	cin >> n >> k;

	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}

	vector<P> b(n, make_pair(-1, -1));
	ll now = 0, cnt = 0;
	while(true) {
		if (b[now].first == -1) b[now].first = cnt;
		else if (b[now].second == -1) b[now].second = cnt;

		if (cnt == k) { cout << now + 1 << endl; return 0; }
		if (b[now].second != -1 && (k - b[now].first) % (b[now].second - b[now].first) == 0) { cout << now + 1 << endl; return 0; }

		cnt++;
		now = a[now];
	}

	return 0;
}