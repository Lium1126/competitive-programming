#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	string s, tmp;
	cin >> s;
	
	// 先頭のaを処理
	tmp = s;
	bool flag = true;
	ll cnt = 0;
	for (ll i = 0;i < tmp.length() / 2 && tmp[i] == 'a' && flag;i++) {
		if (tmp[i] != tmp[tmp.length() - i - 1]) flag = false;
		else {
			cnt++;
			s.pop_back();
		}
	}
	s.erase(s.begin(), s.begin() + cnt);
	
	if (s.length() == 0) cout << "Yes" << endl;
	else if (flag == false) cout << "No" << endl;
	else {
		tmp = s;
		reverse(tmp.begin(), tmp.end());
		for (ll i = 0;i < tmp.length() && tmp[i] == 'a';i++) {
			s.pop_back();
		}
		if (s.length() == 0) cout << "Yes" << endl;
		else {
			bool flag = true;
			rep(i, s.length() / 2) {
				if (s[i] != s[s.length() - i - 1]) flag = false;
			}
			cout << (flag ? "Yes" : "No") << endl;
		}
	}

	return 0;
}