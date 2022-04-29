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
	vector<ll> used(2005, 0);
	ll a;
	rep(i, n) {
		cin >> a;
		used[a] = 1;
	}
	rep(i, 2001) {
		if (used[i] == 0) {
			cout << i << endl;
			return 0;
		}
	}
	
	return 0;
}