#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
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

int main() {
	ll n;
	cin >> n;
	vector<ll> A(n);
	rep(i, n) cin >> A[i];

	unordered_map<ll, ll> freq;
    ll left = 0;
    ll ans = 0;

    rep(right, n) {
        freq[A[right]]++;

        while (freq[A[right]] > 2) {
            freq[A[left]]--;
            if (freq[A[left]] == 0) {
                freq.erase(A[left]);
            }
            left++;
        }

        bool isValid = true;
        for (const auto& [key, value] : freq) {
            if (value != 2) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            ans = max(ans, right - left + 1);
        }
    }

	cout << ans << endl;

	return 0;
}