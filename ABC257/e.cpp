#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

string s_max(string a, string b) {
	if (a.length() > b.length()) return a;
	else if (b.length() > a.length()) return b;
	else return (a > b ? a : b);
}

int main() {
	ll n;
	cin >> n;
	vector<ll> c(10);
	for (ll i = 1;i <= 9;i++) cin >> c[i];
	vector<string> dp(1000005, "");
	string ans = "";

	for (ll i = n;i > 0;i--) {
		if (i != n && dp[i] == "") continue;
		for (ll j = 1;j <= 9;j++) {
			if (i - c[j] < 0) continue;
			string tmp = dp[i] + (char)(j + '0');
			dp[i - c[j]] = max(dp[i - c[j]], tmp);
			ans = s_max(ans, dp[i - c[j]]);
		}
		for (ll j = n;j >= 0;j--) cout << dp[j] << ' ';
		cout << endl;
	}
	ans = s_max(ans, dp[0]);

	cout << ans << endl;

	return 0;
}