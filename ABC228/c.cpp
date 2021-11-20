#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

typedef pair<ll, ll> P;

int main()
{
	ll n, k;
	cin >> n >> k;

	vector<ll> v, sc;

	ll in;
	rep(i, n) {
		ll sum = 0;
		rep(j, 3) {
			cin >> in;
			sum += in;
		}
		v.push_back(sum);
		sc.push_back(sum);
	}

	// 現在のk位の得点は？
	ll r = 0;
	std::sort(v.begin(), v.end(), std::greater<ll>());
	r = v[k - 1];

	rep(i, n) {
		if (sc[i] + 300 >= r) {
			cout << "Yes" << endl;
		}
		else 
		{
			cout << "No" << endl;
		}
	}

	return 0;
}