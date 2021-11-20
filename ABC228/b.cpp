#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

struct UnionFind
{
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

	UnionFind(int N) : par(N)
	{ //最初は全てが根であるとして初期化
		for (int i = 0; i < N; i++)
			par[i] = i;
	}

	int root(int x)
	{ // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x)
			return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y)
	{					  // xとyの木を併合
		int rx = root(x); //xの根をrx
		int ry = root(y); //yの根をry
		if (rx == ry)
			return;	  //xとyの根が同じ(=同じ木にある)時はそのまま
		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
	}

	bool same(int x, int y)
	{ // 2つのデータx, yが属する木が同じならtrueを返す
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};

vector<ll> a;
UnionFind uf(100005);

void solve(ll x, ll o)
{
	uf.unite(x, o);
	if (!uf.same(x, a[o]))
		solve(x, a[o]);
}

int main()
{
	ll n, x;
	cin >> n >> x;

	x--;

	ll in;
	rep(i, n)
	{
		cin >> in;
		in--;
		a.push_back(in);
	}

	solve(x, a[x]);

	vector<ll> cnt(n);
	rep(i, n)
	{
		cnt[uf.root(i)]++;
	}

	cout << cnt[uf.root(x)] << endl;

	return 0;
}