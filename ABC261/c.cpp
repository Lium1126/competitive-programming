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
	ll n;
	cin >> n;

	string s;
	map<string, ll> m;

	rep(i, n) {
		cin >> s;
		if (m[s] == 0) cout << s << endl;
		else cout << s << "(" << m[s] << ")" << endl;
		m[s]++;
	}

	return 0;
}