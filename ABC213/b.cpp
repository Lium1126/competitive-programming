#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>
#include <algorithm>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
typedef pair<ll, ll> P;

int main() {
	ll n;
	cin >> n;
	vector<P> a(n);
	
	rep(i, n) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}

	sort(a.begin(), a.end(), greater<P>());
	cout << a[1].second << endl;

	return 0;
}