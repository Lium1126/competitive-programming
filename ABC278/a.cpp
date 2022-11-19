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
	ll n, k, in;
	cin >> n >> k;

	queue<ll> que;
	rep(i, n) {
		cin >> in;
		que.push(in);
	}

	rep(i, k) {
		que.pop();
		que.push(0);
	}

	while (!que.empty()) {
		ll tmp = que.front(); que.pop();
		cout << tmp << ' ';
	}
	cout << endl;

	return 0;
}