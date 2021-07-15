#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, k;
ll a[200005];
ll b[200005];

int rec(int i, int j) {
  int res;
  if (i == n) {
    // 品物がもう残っていないときは、価値の和の最大値は0で確定
    res = 0;
  } else if (j < a[i]) {
    // 残りの容量が足りず品物iを入れられないので、入れないパターンだけ処理
    // i+1 以降の品物のみを使ったときの最大値をそのままこの場合の最大値にする
    res = rec(i + 1, j);
  } else {
    // 品物iを入れるか入れないか選べるので、両方試して価値の和が大きい方を選ぶ
    res = max(
        rec(i + 1, j),
        rec(i + 1, j - a[i])
    );
  }
  return res;
}

void solve() {
  // 0番目以降で容量W以下の場合の結果を表示する
  cout << rec(0, k) << endl;
}

int main() {
    cin >> n >> m >> k;
    for (ll i = 0;i < n;i++) {
        cin >> a[i];
    }
    for (ll i = 0;i < m;i++) {
        cin >> b[i];
    }

    solve();

    return 0;
}
