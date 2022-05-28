#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i,n) for(ll i = 0;i < n;i++)

using namespace std;

vector<bool> created(3000005, false);
vector<ll> v;
ll n, w;

void solve(ll now, ll cnt, ll idx) {
//	cout << "!" << now << endl;
	created[now] = true;
	if (cnt == 3) return;
	if (idx == n) return;
	solve(now + v[idx], cnt + 1, idx + 1);
	solve(now, cnt, idx + 1);
}

int main() {
	cin >> n >> w;
	ll a;
	rep (i, n) {
		cin >> a;
		v.push_back(a);
	}
	solve(0, 0, 0);

	ll cnt = 0;
	for (ll i = 1;i <= w;i++) {
		if(created[i]) {
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}