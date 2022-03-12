#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef pair<char, ll> P;

int main() {
	ll v, a, b, c;
	cin >> v >> a >> b >> c;
	vector<P> rol = {P{'F', a}, P{'M', b}, P{'T', c}};
	ll now = 0;
	while (v >= rol[now].second) {
		v -= rol[now].second;
		now = (now + 1) % 3;
	}
	cout << rol[now].first << endl;
	return 0;
}