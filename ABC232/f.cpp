#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

struct Edge
{
	long long to;
	long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;

void dijkstra(const Graph &G, int s, vector<ll> &dis)
{
	ll N = G.size();
	dis.resize(N, INF);
	priority_queue<P, vector<P>, greater<P>> pq; // 「仮の最短距離, 頂点」が小さい順に並ぶ
	dis[s] = 0;
	pq.emplace(dis[s], s);
	while (!pq.empty())
	{
		P p = pq.top();
		pq.pop();
		ll v = p.second;
		if (dis[v] < p.first)
		{ // 最短距離で無ければ無視
			continue;
		}
		for (auto &e : G[v])
		{
			if (dis[e.to] > dis[v] + e.cost)
			{ // 最短距離候補なら priority_queue に追加
				dis[e.to] = dis[v] + e.cost;
				pq.emplace(dis[e.to], e.to);
			}
		}
	}
}

int main()
{
	ll n, m;
	cin >> n >> m;

	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];

	Graph G;
	rep(i, n)
	{
		vector<Edge> tmp;
		rep(j, n)
		{
			if (i == j)
				continue;
			Edge e = Edge{j, (a[i] + b[j]) % m};
			tmp.push_back(e);
		}
		G.push_back(tmp);
	}

	vector<ll> dis;
	dijkstra(G, 0, dis);

	cout << dis[n - 1] << endl;

	return 0;
}