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

class FenwickTree {
private:
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) : n(size) {
        tree.resize(n + 1, 0);
    }

    void add(int index, int value) {
        while (index <= n) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int sum(int index) {
        int result = 0;
        while (index > 0) {
            result += tree[index];
            index -= index & -index;
        }
        return result;
    }

    int rangeSum(int left, int right) {
        return sum(right) - sum(left - 1);
    }

	int size() {
		return tree.size();
	}
};

int findPosition(FenwickTree& fenwick, int target) {
    int low = 1, high = fenwick.size(), mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (fenwick.sum(mid) >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
	ll n, q;
	cin >> n >> q;
	vector<ll> num(n, 1);
	vector<P> v(n);
	rep(i, n) v[i] = P{i, 1};

	FenwickTree fenwick(n);
	irep(i, n) fenwick.add(i, v[i].second);

	ll cmd, x, c;
	while(q--) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> x >> c;
			ll tmp = findPosition(fenwick, x);
			tmp--;

			num[c] += v[tmp].second;
			num[v[tmp].first] -= v[tmp].second;

			v[tmp].first = c;
			if (tmp < v.size() - 1 && v[tmp].first == v[tmp + 1].first) {
				fenwick.add(tmp, v[tmp + 1].second);
				fenwick.add(tmp + 1, -v[tmp + 1].second);
				v[tmp].second += v[tmp + 1].second;
				v.erase(v.begin() + (tmp + 1));
			}
			if (tmp > 1 && v[tmp].first == v[tmp - 1].first) {
				fenwick.add(tmp - 1, v[tmp].second);
				fenwick.add(tmp, -v[tmp].second);
				v[tmp - 1].second += v[tmp].second;
				v.erase(v.begin() + tmp);
			}
		} else {
			cin >> c;
			cout << num[c--] << endl;
		}
	}

	return 0;
}