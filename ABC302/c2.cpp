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

ll diff(string s, string t) {
	ll cnt = 0;
	rep(i, s.length()) if (s[i] != t[i]) cnt++;
	return cnt;
}

bool solve(string s, set<string> st) {
	if (st.size() == 1) {
		string target = *st.begin();
		return (diff(target, s) == 1 ? true : false);
	}

	bool f = false;
	for (auto itr = st.begin();itr != st.end();itr++) {
		set<string> st2 = st;
		if (diff(*itr, s) == 1) {
			st2.erase(*itr);
			f |= solve(*itr, st2);
		}
	}
	return f;
}

int main() {
	ll n, m;
	cin >> n >> m;
	set<string> s;
	vector<string> v;
	string in;
	rep(i, n) {
		cin >> in;
		s.insert(in);
		v.push_back(in);
	}

	bool f = false;
	rep(i, n) {
		set<string> s2 = s;
		s2.erase(v[i]);
		f |= solve(v[i], s2);
	}

	cout << (f ? "Yes" : "No") << endl;

	return 0;
}