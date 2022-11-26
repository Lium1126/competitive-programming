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
	ll h, w;
	cin >> h >> w;
	vector<string> s(h), t(h);
	vector<string> ms(w), mt(w);
	rep(i, h) cin >> s[i];
	rep(i, h) cin >> t[i];

	rep(j, w) {
		string str = "";
		rep(i, h) {
			str += s[i][j];
		}
		ms[j] = str;
	}

	rep(j, w) {
		string str = "";
		rep(i, h) {
			str += t[i][j];
		}
		mt[j] = str;
	}

//	rep(i, w) cout << ms[i] << endl;
//	rep(i, w) cout << mt[i] << endl;

	sort(ms.begin(), ms.end());
	sort(mt.begin(), mt.end());

	cout << (ms == mt ? "Yes" : "No") << endl;

	return 0;
}