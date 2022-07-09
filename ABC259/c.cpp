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
	string s, t;
	cin >> s >> t;

	vector<pair<char, int>> tinfo, sinfo;
	int cnt = 1;

	irep(i, t.length() - 1) {
		if (t[i] == t[i - 1]) {
			cnt++;
		} else {
			tinfo.push_back(make_pair(t[i - 1], cnt));
			cnt = 1;
		}
	}
	tinfo.push_back(make_pair(t[t.length() - 1], cnt));

	cnt = 1;
	irep(i, s.length() - 1) {
		if (s[i] == s[i - 1]) {
			cnt++;
		} else {
			sinfo.push_back(make_pair(s[i - 1], cnt));
			cnt = 1;
		}
	}
	sinfo.push_back(make_pair(s[s.length() - 1], cnt));

	if (tinfo.size() != sinfo.size()) { cout << "No" << endl; return 0; }

	rep(i, tinfo.size()) {
		if (tinfo[i].first != sinfo[i].first) {
			cout << "No" << endl;
			return 0;
		} else {
			if (sinfo[i].second == 1){
					if (tinfo[i].second >= 2) {
						cout << "No" << endl;
						return 0;
					}
			} else {
				if (tinfo[i].second < sinfo[i].second) {
					cout << "No" << endl;
					return 0;	
				}
			}
		}
	}

	cout << "Yes" << endl;

	return 0;
}