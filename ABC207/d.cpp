#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <math.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0;i < n;i++)

vector<pair<ll, ll> > s, t;
ll n;

bool jud(vector<pair<ll, ll> > d) {
    bool f = true;
    sort(d.begin(), d.end());
    for (ll i = 0;i < n && f;i++) {
        if (d[i] != s[i]) f = false;
    }
    return f;
}

double solve(ll d) {
    return((double)d * M_PI / 180.0);
}

int main() {
    ll x, y;
    cin >> n;
    bool flag = false;
    rep(i, n) {
        cin >> x >> y;
        s.push_back(make_pair(x, y));
    }
    rep(i, n) {
        cin >> x >> y;
        t.push_back(make_pair(x, y));
    }

    // sの全ての点を、一つ目の点が原点に来るよう合わせる
    ll temp_s_x = s[0].first;
    ll temp_s_y = s[0].second;
    rep(i, n) {
        s[i].first -= temp_s_x;
        s[i].second -= temp_s_y;
    }

    // sをソート
    sort(s.begin(), s.end());

    // tのある点を原点とした時に、4方向に回転させて一致するか判定
    rep(i, n) {
        // tをdにコピー
        vector<pair<ll, ll> > d;
        copy(t.begin(), t.end(), back_inserter(d));

        // dの全ての点を、t[i]を原点にするよう移動
        rep(j, n){
            d[j].first -= t[i].first;
            d[j].second -= t[i].second;
        }

//        cout << "--------------" << endl;
//        rep(j, n) cout << d[j].first << " " << d[j].second << endl;

        vector<pair<ll, ll> > u;
        copy(d.begin(), d.end(), back_inserter(u));

        // 4角度に回転
        rep(k, 4) {
            // 90度回転
            rep(l, n) {
                ll temp_x = d[l].first, temp_y = d[l].second;
                u[l].first = -temp_y;
                u[l].second = temp_x;
            }

//            cout << "--------------" << endl;
//            cout << k << endl;
//            rep(j, n) cout << d[j].first << " " << d[j].second << endl;

            // 判定
            if (!flag) flag = jud(u);
        }

//        cout << "--------------" << endl;
//        rep(j, n) cout << d[j].first << " " << d[j].second << endl;

    }

//    cout << "------------" << endl;
//    rep(j, n) cout << s[j].first << " " << s[j].second << endl;
//    cout << "------------" << endl;

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
