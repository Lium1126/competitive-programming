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
	cin >> n;
	ll a;
	set<ll> s;
	rep(i, n) {
		cin >> a;
		s.insert(a);
	}
	cout << s.size() << endl;
	return 0;
}