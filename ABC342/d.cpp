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

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

void print(vector<ll> a) {
	cout << '{';
	for (ll v : a) cout << v << ' ';
	cout << '}';
}

int main() {
	ll n;
	cin >> n;
	ll cnt = 0;
	map<vector<ll>, ll> m;
	ll a;
	rep(i, n) {
		cin >> a;
		if (a == 0) {
			cnt++;
			continue;
		}

		const auto &res = prime_factorize(a);

		vector<ll> tmp;
		for (auto p : res) {
			if (p.second % 2 == 1) tmp.push_back(p.first);
		}

		m[tmp]++;
	}

	ll ans = 0;
	for (const auto& [key, value] : m){
		// print(key); cout << ": " << value << endl;
        ans += (value * (value - 1)) / 2;
    }

	cout << ans + (cnt * (n - cnt)) + (cnt * (cnt - 1)) / 2 << endl;

	return 0;
}