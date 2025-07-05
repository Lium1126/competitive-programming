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

bool isGS(vector<ll> a) {
	ll n = a.size();
	if (n < 3) return true;

	bool flg = true;

	for (ll i = 0;i < (n - 2) && flg;i++) {
		if ((a[i] * a[i + 2]) != (a[i + 1] * a[i + 1])) {
			flg = false;
		}
	}

	return flg;
}

int main() {
	ll t;
	cin >> t;

	while(t--) {
		ll n, in;
		cin >> n;

		vector<ll> pos, neg;
		rep(i, n) {
			cin >> in;
			if (in < 0) neg.push_back(in);
			else pos.push_back(in);
		}

		if (n < 3) {
			cout << "Yes" << endl;
			continue;
		}

		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end(), greater<ll>());

		if (pos.size() == 0) {
			cout << (isGS(neg) ? "Yes" : "No") << endl;
		} else if (neg.size() == 0) {
			cout << (isGS(pos) ? "Yes" : "No") << endl;
		} else {
			ll tmp = pos.size() - neg.size();
			if (abs(tmp) > 1) {
				cout << "No" << endl;
				continue;
			}

			vector<ll> v;
			if (pos.size() > neg.size()) {
				rep(i, neg.size()) {
					v.push_back(pos[i]);
					v.push_back(neg[i]);
				}
				v.push_back(pos[pos.size() - 1]);
			} else if (pos.size() < neg.size()) {
				rep(i, pos.size()) {
					v.push_back(neg[i]);
					v.push_back(pos[i]);
				}
				v.push_back(neg[neg.size() - 1]);
			} else {
				rep(i, pos.size()) {
					v.push_back(pos[i]);
					v.push_back(neg[i]);
				}
				if (isGS(v)) {
					cout << "Yes" << endl;
					continue;
				}

				v.clear();
				rep(i, pos.size()) {
					v.push_back(neg[i]);
					v.push_back(pos[i]);
				}
				if (isGS(v)) {
					cout << "Yes" << endl;
					continue;
				}

				cout << "No" << endl;
				continue;
			}

			cout << (isGS(v) ? "Yes" : "No") << endl;
		}
	}

	return 0;
}