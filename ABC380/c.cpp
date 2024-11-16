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
	ll n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<P> lan;
   	char current_char = s[0];
	ll cnt = 1;

	irep(i, n - 1) {
        if (s[i] == current_char) {
            cnt++;
        } else {
            lan.push_back(P(current_char - '0', cnt));
            current_char = s[i];
            cnt = 1;
        }
    }
    lan.push_back(P(current_char - '0', cnt));

	cnt = 0;
	rep(i, lan.size()) {
		if (lan[i].first == 1) cnt++;
		if (cnt == k) swap(lan[i], lan[i - 1]);
	}

	for (P p: lan) {
		rep(i, p.second) cout << p.first;
	}
	cout << endl;

	return 0;
}