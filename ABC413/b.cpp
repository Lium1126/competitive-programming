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
	ll n;
	cin >> n;

	vector<string> s(n);
	rep(i, n) cin >> s[i];

	set<string> st;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if (i == j) continue;
			st.insert(s[i] + s[j]);
			st.insert(s[j] + s[i]);
		}
	}

	cout << st.size() << endl;

	return 0;
}
