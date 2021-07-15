#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

vector<pair <ll, pair<double, double> > > v;

ll jud(ll i, ll j) {
    if (v[i].second.second < v[j].second.first || v[i].second.first > v[j].second.second) return 0;
    else{
//        cout << i << ' ' << j << endl;
        return 1;
    }
}

int main() {
    ll n;
    ll cnt = 0;

    ll t;
    double l, r;

    cin >> n;
    rep(i, n) {
        cin >> t >> l >> r;
        v.push_back(make_pair(t, make_pair(l, r)));

        switch (t)
        {
        case 2:
            v[i].second.second-=0.5;
//            cout << i << ":" << 2 << endl;
            break;
        case 3:
            v[i].second.first+=0.5;
//            cout << i << ":" << 3 << endl;
            break;
        case 4:
            v[i].second.first+=0.5;
            v[i].second.second-=0.5;
//            cout << i << ":" << 4 << endl;
            break;
        }
    }

//    rep(i, n)         cout << i << ":" << v[i].second.first << ' ' << v[i].second.second << endl;

    rep(i, n - 1) {
        for (ll j = i + 1;j < n;j++) {
            cnt += jud(i, j);
        }
    }

    cout << cnt << endl;

    return 0;
}
