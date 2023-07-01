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
typedef pair<P, ll> PP;

P yakubun(P p) {
	ll g = gcd(p.first, p.second);
	return P{p.first / g, p.second / g};
}

bool fcomp(const PP& a, const PP& b) { 
	if (a.first != b.first) {
		return a.first.first * b.first.second > b.first.first * a.first.second;
	} else {
		return a.second < b.second;
	}
}

int main() {
	ll n;
	cin >> n;
	vector<PP> p;
	ll a, b;
	rep(i, n) {
		cin >> a >> b;
		
		P tmp = P{a, a + b};
		tmp = yakubun(tmp);
		p.push_back(PP{tmp, i + 1});
	}
	sort(p.begin(), p.end(), fcomp);
	// rep(i, n) {
	// 	cout << "(" <<p[i].first.first<<"/"<<p[i].first.second<<")" << ", "<<p[i].second<<endl;;
	// }
	rep(i, n) {
		cout << p[i].second << ' ';
	}
	cout << endl;
	return 0;
}