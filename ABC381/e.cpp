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

class SegmentTree {
private:
    std::vector<ll> tree;
    std::vector<ll> data;
    ll n;

    void build(ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = start;
        } else {
            ll mid = (start + end) / 2;
            ll leftChild = 2 * node + 1;
            ll rightChild = 2 * node + 2;

            build(leftChild, start, mid);
            build(rightChild, mid + 1, end);

            if (data[tree[leftChild]] >= data[tree[rightChild]]) {
                tree[node] = tree[leftChild];
            } else {
                tree[node] = tree[rightChild];
            }
        }
    }

    ll query(ll node, ll start, ll end, ll l, ll r) {
        if (r < start || end < l) {
            return -1; // 範囲外
        }
        if (l <= start && end <= r) {
            return tree[node];
        }

        ll mid = (start + end) / 2;
        ll leftChild = 2 * node + 1;
        ll rightChild = 2 * node + 2;

        ll leftIndex = query(leftChild, start, mid, l, r);
        ll rightIndex = query(rightChild, mid + 1, end, l, r);

        if (leftIndex == -1) return rightIndex;
        if (rightIndex == -1) return leftIndex;

        return (data[leftIndex] >= data[rightIndex]) ? leftIndex : rightIndex;
    }

public:
    SegmentTree(const std::vector<ll>& input) : data(input) {
        n = input.size();
        tree.resize(4 * n, -1);
        build(0, 0, n - 1);
    }

    ll rangeMaxQuery(ll l, ll r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
	ll n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	vector<ll> one(n + 1, 0), two(n + 1, 0);
	rep(i, n) {
		if (s[i] == '1') {
			one[i + 1] = one[i] + 1, two[i + 1] = two[i];
		} else if (s[i] == '2') {
			one[i + 1] = one[i], two[i + 1] = two[i] + 1;
		} else {
			one[i + 1] = one[i], two[i + 1] = two[i];
		}
	}

	// for (ll value : one) cout << value << ' ';
	// cout << endl;
	// for (ll value : two) cout << value << ' ';
	// cout << endl;

	vector<ll> v(n);
	rep(i, n) {
		if (s[i] != '/') v[i] = 0;
		else v[i] = 1 + min(one[i + 1], two[n] - two[i + 1]) * 2;
	}

	// for (ll value : v) cout << value << ' ';

	SegmentTree segTree(v);
	ll l, r;
	while(q--) {
		cin >> l >> r;
		l--, r--;

		ll idx = segTree.rangeMaxQuery(l, r);
		// cout << "idx " << idx << endl;

		if (s[idx] != '/') cout << 0 << endl;
		else cout << 1 + min(one[idx + 1] - one[l], two[r + 1] - two[idx + 1]) * 2 << endl;
	}

	return 0;
}