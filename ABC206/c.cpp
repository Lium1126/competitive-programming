#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

#define ll long long
#define rep(i,n) for (int i = 0;i < n;i++)

int main() {
    int n;
    int in;
    ll ans = 0;
    vector<int> v;
    map<int, int> a;
    set<int> s;
    int cnt[300005] = {};

    cin >> n;
    rep(i, n) {
        cin >> in;

        if (s.find(in) == s.end()) {
            s.insert(in);
            a.insert(make_pair(in, i));
        }

        v.push_back(in);
    }

    rep(i, n) {
        int target = v[n - i - 1];
        if(i == 0) {
            cnt[a[target]]++;
        } else {
            ans += (i - cnt[a[target]]);
            cnt[a[target]]++;
        }
    }

    cout << ans << endl;

    return(0);
}
