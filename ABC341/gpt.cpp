#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
    int zeros;
    int ones;
    bool lazy;

    Node() : zeros(0), ones(0), lazy(false) {}
};

class SegmentTree {
private:
    vector<Node> tree;
    vector<bool> lazy;

    void propagate(int idx, int start, int end) {
        if (lazy[idx]) {
            tree[idx].zeros = (end - start + 1) - tree[idx].zeros;
            tree[idx].ones = (end - start + 1) - tree[idx].ones;

            if (start != end) {
                lazy[2 * idx + 1] = !lazy[2 * idx + 1];
                lazy[2 * idx + 2] = !lazy[2 * idx + 2];
            }

            lazy[idx] = false;
        }
    }

    void updateRangeUtil(int idx, int start, int end, int l, int r) {
        propagate(idx, start, end);

        if (start > r || end < l)
            return;

        if (start >= l && end <= r) {
            tree[idx].zeros = (end - start + 1) - tree[idx].zeros;
            tree[idx].ones = (end - start + 1) - tree[idx].ones;

            if (start != end) {
                lazy[2 * idx + 1] = !lazy[2 * idx + 1];
                lazy[2 * idx + 2] = !lazy[2 * idx + 2];
            }

            return;
        }

        int mid = (start + end) / 2;
        updateRangeUtil(2 * idx + 1, start, mid, l, r);
        updateRangeUtil(2 * idx + 2, mid + 1, end, l, r);

        tree[idx].zeros = tree[2 * idx + 1].zeros + tree[2 * idx + 2].zeros;
        tree[idx].ones = tree[2 * idx + 1].ones + tree[2 * idx + 2].ones;
    }

    bool queryUtil(int idx, int start, int end, int l, int r) {
        propagate(idx, start, end);

        if (start > r || end < l)
            return true;

        if (start >= l && end <= r) {
            return tree[idx].zeros == 0 || tree[idx].ones == 0;
        }

        int mid = (start + end) / 2;
        return queryUtil(2 * idx + 1, start, mid, l, r) && queryUtil(2 * idx + 2, mid + 1, end, l, r);
    }

public:
    SegmentTree(int n) {
        int x = (int)(ceil(log2(n)));
        int max_size = 2 * (int)pow(2, x) - 1;
        tree.resize(max_size);
        lazy.resize(max_size, false);
    }

    void updateRange(int l, int r) {
        updateRangeUtil(0, 0, tree.size() / 2 - 1, l, r);
    }

    bool query(int l, int r) {
        return queryUtil(0, 0, tree.size() / 2 - 1, l, r);
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    SegmentTree segtree(N);

    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            segtree.updateRange(i, i);
        }
    }

    while (Q--) {
        int type, L, R;
        cin >> type >> L >> R;
        --L; --R;

        if (type == 1) {
            segtree.updateRange(L, R);
        } else {
            bool result = segtree.query(L, R);
            if (result)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
