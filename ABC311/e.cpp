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

#define MAX 3005

ll dp[MAX][MAX],G[MAX][MAX];

ll getLargestSquare(int h,int w){
    ll maxWidth = 0;
    for(int i = 0;i < h;++i){
        for(int j = 0;j < w;++j){
            // 1が汚れたタイルなので、面積は0に、0は綺麗なタイルなので、面積が1になる
            dp[i][j] = (G[i][j] + 1) % 2;
            // 面積が1の場合、最大面積を計算する処理がスルーされるので、面積を暫定でいれる
            maxWidth |= dp[i][j];
        }
    }

    for(int i = 1;i < h;++i){
        for(int j = 1;j < w;++j){
            // 汚れている状態
            if(G[i][j]){
                dp[i][j] = 0;
            }else{
                // 左上,上,左の最小値の+1がdp[i][j]の正方形の最大面積となる
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j - 1])) + 1;
                maxWidth = max(maxWidth,dp[i][j]);
            }
        }
    }

	ll ans = 0;
    for(int i = 0;i < h;++i){
        for(int j = 0;j < w;++j){
//			cout << dp[i][j] << ' ';
			ans += dp[i][j];
		}
//		cout << endl;
	}

//    return maxWidth * maxWidth;
	return ans;
}

int main(){
    ll h, w, n;
	cin >> h >> w >> n;
	rep(i, h) rep(j, w) G[i][j] = 0;
	ll a, b;
	rep(i, n) {
		cin >> a >> b;
		G[a - 1][b - 1] = 1;
	}
    
	cout << getLargestSquare(h, w) << endl;

    return 0;
}