#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll bitcnt(ll a) {
	ll cnt = 0;
	rep(i, 6) {
		if ((a & 1) == 1) cnt++;
		a >>= 1;
	}
	return cnt;
}

string makestr(ll i) {
	string ret = "";
	rep(j, 6) {
		if ((i & 1) == 1) ret = '#' + ret;
		else ret = '.' + ret;
		i >>= 1;
	}
	return ret;
}

vector<string> make_mask() {
	vector<string> ret;
	for (ll i = 15;i < 64;i++) {
		if (bitcnt(i) >= 4) {
			ret.push_back(makestr(i));
		}
	}
	return ret;
}

int main() {
	ll n;
	cin >> n;
	vector<string> maps(n);
	rep(i, n) cin >> maps[i];
	vector<string> mask;
	mask = make_mask();
//	for (string x : mask) cout << x << endl;

	bool flag = false;
	rep(i, n) {
		for (string cmp : mask) {
			if (maps[i].find(cmp) != string::npos) flag = true;
		}
	}

	// 転置
	vector<string> maze(n);
	rep(i, n) {
		string tmp = "";
		rep(j, n) {
			tmp += maps[j][i];
		}
		maze[i] = tmp;
	}
	rep(i, n) {
		for (string cmp : mask) {
			if (maze[i].find(cmp) != string::npos) flag = true;
		}
	}

	// 斜め
	vector<string> m;
	for (ll i = n - 1;i >= 0;i--) {
		ll j = n - (i + 1);
		string tmp = "";
		for (ll r = 0;r <= j;r++) {
			tmp += maps[r][i + r];
		}
		m.push_back(tmp);
	}
	for (ll i = 1;i < n;i++) {
		ll j = n - (i + 1);
		string tmp = "";
		for (ll r = 0;r <= j;r++) {
			tmp += maps[i + r][r];
		}
		m.push_back(tmp);
	}
	for (ll i = 0;i < n;i++) {
		string tmp = "";
		for (ll j = 0;j <= i;j++) {
			tmp += maps[j][i - j];
		}
		m.push_back(tmp);
	}
	for (ll i = 1;i < n;i++) {
		string tmp = "";
		for (ll j = 0;j + i < n;j++) {
			tmp += maps[i + j][n - 1 - j];
		}
		m.push_back(tmp);
	}

	for (string x : m) for (string cmp : mask) if (x.find(cmp) != string::npos) flag = true;

	cout << (flag ? "Yes" : "No") << endl;
	return 0;
}