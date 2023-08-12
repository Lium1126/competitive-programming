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
	ll n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	vector<ll> a(n);
	ll in;
	rep(i, n) {
		cin >> in;
		a[i] = in - 1;
	}

	vector<vector<ll>> v(m, vector<ll>());
	rep(i, n) {
		v[a[i]].push_back(i);
	}	
	/*
	rep(i, m) {
		cout << i << ": ";
		for (ll out : v[i]) cout << out << ' ';
		cout << endl;
	}
	*/

	rep(i, m) {
	    std::rotate(v[i].rbegin(), v[i].rbegin() + 1, v[i].rend());
	}
	/*
	rep(i, m) {
		cout << i << ": ";
		for (ll out : v[i]) cout << out << ' ';
		cout << endl;
	}
	*/

	vector<ll> color(m, 0);
	rep(i, n) {
		ll nowcolor = a[i];
		cout << s[v[nowcolor][color[nowcolor]]];
		color[nowcolor]++;
	}
	cout << endl;

	return 0;
}