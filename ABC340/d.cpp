#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <functional>
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

constexpr long long INF = (1LL << 60);

// 辺の情報
struct Edge
{
	// 行先
	ll to;

	// コスト
	ll cost;
};

using Graph = std::vector<std::vector<Edge>>;

// { distance, from }
using Pair = std::pair<long long, ll>;

// ダイクストラ法 (1.1 基本実装)
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void Dijkstra(const Graph& graph, std::vector<long long>& distances, ll startIndex)
{
	// 「現時点での最短距離, 頂点」の順に取り出す priority_queue
	// デフォルトの priority_queue は降順に取り出すため std::greater を使う
	std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
	q.emplace((distances[startIndex] = 0), startIndex);

	while (!q.empty())
	{
		const long long distance = q.top().first;
		const ll from = q.top().second;
		q.pop();

		// 最短距離でなければ処理しない
		if (distances[from] < distance)
		{
			continue;
		}

		// 現在の頂点からの各辺について
		for (const auto& edge : graph[from])
		{
			// to までの新しい距離
			const long long d = (distances[from] + edge.cost);

			// d が現在の記録より小さければ更新
			if (d < distances[edge.to])
			{
				q.emplace((distances[edge.to] = d), edge.to);
			}
		}
	}
}

int main() {
	ll n, a, b, x;
	cin >> n;

	Graph graph(n);
	rep(i, n - 1) {
		cin >> a >> b >> x;

		graph[i].push_back({i + 1, a});
		// graph[i + 1].push_back({i, a});

		graph[i].push_back({x - 1, b});
		// graph[x - 1].push_back({i, b});
	}

	vector<ll> dist(n, INF);
	Dijkstra(graph, dist, 0);

	cout << dist[n - 1] << endl;

	return 0;
}