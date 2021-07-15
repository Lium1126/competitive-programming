#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
#define rep(i,n) for (ll i = 0;i < n;i++)
#define MAX_V (100005)
#define INF (1<<30)

struct edge {
    ll to;
    ll cost;
};

typedef pair<int, int> P;  // first: 最短距離, second: 頂点番号

ll n, q, d[MAX_V];
vector<edge> G[MAX_V]; // 隣接リスト表現

void dijkstra(ll s, ll t) {
    fill(d, d + n, INF);
    d[s] = 0;  // 始点sへの最短距離は0

    priority_queue<P, vector<P>, greater<P> > que;  // 距離が小さい順に取り出せるようgreater<P>を指定
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        ll v = p.second;  // 更新した頂点の中で距離が最小の頂点v
        if (d[v] < p.first) {
            continue;
        }
        for (auto e : G[v]) {  // 頂点vから出る辺eを走査
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }

    if (!(d[t] % 2)) cout << "Town" << endl;
    else cout << "Road" << endl;
}

int main() {
    cin >> n >> q;

    ll from, to;
    rep(i, n - 1) {
        cin >> from >> to;
        edge e; e.to = to; e.cost = 1;
        G[from].push_back(e);
        e.to = from;
        G[to].push_back(e);
    }

    rep(i, q) {
        cin >> from >> to;
        dijkstra(from, to);
    }


    return 0;
}
