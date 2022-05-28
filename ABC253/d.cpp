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
	ll n, a, b;
	cin >> n >> a >> b;
	if (a > b) swap(a, b);

	ll ab = std::lcm(a, b);

	ll sum = (n * (n + 1)) / 2;
	ll a_n = n / a;
	ll b_n = n / b;
	ll ab_n = n / ab;
	ll a_sum = (a_n * (2 * a + (a_n - 1) * a)) / 2;
	ll b_sum = (b_n * (2 * b + (b_n - 1) * b)) / 2;
	ll ab_sum = (ab_n * (2 * ab + (ab_n - 1) * ab)) / 2;

	if (a == b) cout << sum - a_sum << endl;
	else cout << sum - a_sum - b_sum + ab_sum << endl;

	return 0;
}