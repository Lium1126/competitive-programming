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
	
	cout << (n / 10000) + ((n % 10000) / 5000) + ((n % 5000) / 1000) << endl;

	return 0;
}