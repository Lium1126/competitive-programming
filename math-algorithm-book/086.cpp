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
	ll n;
	string s;
	cin >> n >> s;

	ll tmp = 0;
	bool flag = true;
	rep(i, n) {
		if (s[i] == '(') tmp++;
		if (s[i] == ')') tmp--;
		if (tmp < 0) {
			flag = false;
			break;
		}
	}

	flag = (tmp != 0 ? false : true);
	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}