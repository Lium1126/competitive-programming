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
	vector<ll> a(4);
	rep(i, 4) {
		cin >> a[i];
	}

	set<ll> st;
	rep(i, 4) {
		st.insert(a[i]);
	}

	if (st.size() == 2) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}