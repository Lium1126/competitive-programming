#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    UnionFind uf(13);

    uf.unite(1, 3);
    uf.unite(1, 5);
    uf.unite(1, 7);
    uf.unite(1, 8);
    uf.unite(1, 10);
    uf.unite(1, 12);

    uf.unite(4, 6);
    uf.unite(4, 9);
    uf.unite(4, 11);

    int x, y;
    cin >> x >> y;
    if (uf.same(x, y)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return(0);
}
