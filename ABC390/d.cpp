#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

set<ll> s;

void generateCombinations(int n, int i, int start, std::vector<ll>& combination, std::vector<std::vector<ll>>& result) {
    if (combination.size() == i) {
        result.push_back(combination);
        return;
    }

    for (int num = start; num < n; ++num) {
        combination.push_back(num);
        generateCombinations(n, i, num + 1, combination, result);
        combination.pop_back();
    }
}

ll fullXOR(vector<ll> a) {
	ll res = 0;
	rep(i, a.size()) {
		res ^= a[i];
	}
	return res;
}

int main() {
	ll n;
	cin >> n;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	s.insert(fullXOR(a));

	for (ll i = 2;i <= n;i++) {
		// cout << "i: " << i << endl;

		vector<ll> idx;
		vector<vector<ll>> result;
		generateCombinations(n, i, 0, idx, result);

		// for (const auto& comb : result) {
		// 	for (ll num : comb) std::cout << num << " ";
		// 	std::cout << "\n";
		// }

		for (const auto& comb: result) {
			vector<ll> b(n);
			rep(j, n) b[j] = a[j];

			// for (ll num : comb) std::cout << num << " ";
			// std::cout << ": ";

			ll sum = 0;
			for (ll idx: comb) sum += b[idx], b[idx] = 0;
			b[comb[comb.size() - 1]] = sum;

			// for (ll out : b) cout << out << " ";
			// cout << endl;

			s.insert(fullXOR(b));
		}
	}

	// for (auto itr = s.begin();itr != s.end();itr++) cout << *itr << " ";
	// cout << endl;

	cout << s.size() << endl;

	return 0;
}