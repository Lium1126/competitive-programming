#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

vector<ll> a;

// a.begin()+lower~a.end()でtarget以下の個数を返す
ll M (ll lower, ll target) {
    // k以下でaに含まれている個数mは?
    decltype(a)::iterator it = lower_bound(a.begin() + lower, a.end(), target + 1);
    ll m;
    if (it == a.end()) {
        return a.size() - lower;
    } else {
        std::size_t pos = distance(a.begin() + lower, it);
        return pos;
    }
}

int main() {
    ll n, q;
    cin >> n >> q;
    ll temp;
    ll k;

    rep(i, n) {
        cin >> temp;
        a.push_back(temp);
    }

    rep(i, q) {
        cin >> k;
        ll b = 0;
        ll kouho = k;
        ll m;
        do {
            m = M(b, kouho);
//            cout << "!" << m << endl;
            kouho += m;
            b += m;
        } while(m != 0);
        cout << kouho << endl;
    }

    return(0);
}
