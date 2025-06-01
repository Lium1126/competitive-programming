#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
typedef pair<ll, ll> P;

int main() {
	ll n;
	ll in;

	set<ll> s;
	cin >> n;
	rep(i, n) {
		cin >> in;
		s.insert(in);
	}

	cout << s.size() << endl;
	for (auto it = s.begin(); it != s.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}