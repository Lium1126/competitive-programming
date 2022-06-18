#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)
#define N 200005

using namespace std;


vector<vector<pair<ll,bool>>> conn(N);
vector<ll> checked(N,0); // dfs参照
vector<ll> orderList(N,-1); // dfsで通った順番に登録していく
vector<ll> groupList(N,-1); // 各nodeにgroupをつけていく
ll cnt = 0;

void dfs(ll now, ll prev) { 
    // 帰り道に通った順に番号をつける, 重複が起きないように行きにcheckedする
    // orderList[i]はi番のnode
    checked[now]=1;
    for (auto v : conn[now]) {
        // すでに見たところ、親、false(逆向きの枝)
        if (checked[v.first]==1 || v.first==prev || v.second==false) continue;
        dfs(v.first,now);
    }
    // 通った順に番号をつける
    orderList[cnt]=now; cnt++;
    return;
}


void dfs2(ll now, ll group) {
    // nowが今見るnode, groupが登録するgroup番号
    groupList[now]=group;
    for (auto v : conn[now]) {
        // すでにgroup番号が付いてるnode、逆向きでない枝はスルー
        if (groupList[v.first]!=-1 || v.second==true) continue;
        // nowから行けるところに、同じgroup番号をつける
        dfs2(v.first,group);
    }
    return;
}

int main(){
    ll n; cin >> n;
	ll v;
	vector<ll> c(n);
    rep(i, n) {
        cin >> v;
		v--;
        conn[i].push_back({v,true});
        conn[v].push_back({i,false});
    }
    rep(i,n) if (!checked[i]) {
        dfs(i,-1);
    }

    for (ll i  = n - 1;i >= 0;i--) {
        if (orderList[i]==-1) break;
        if (groupList[orderList[i]]!=-1) continue;
        dfs2(orderList[i],orderList[i]);
    }

	rep(i, n) cin >> c[i];

	set<ll> s;
	vector<vector<ll>> vec(N);
	rep(i, n) {
		s.insert(groupList[i]);
		vec[groupList[i]].push_back(i);
	}

	ll ans = 0;
	for (auto itr = s.begin();itr != s.end();itr++) {
		if (vec[*itr].size() == 1) continue;
		ll tmp = __LONG_LONG_MAX__;
        for (int t : vec[*itr]) tmp = min(tmp, c[t]);
        ans += tmp;
	}

	cout << ans << endl;
    
    return 0;
}