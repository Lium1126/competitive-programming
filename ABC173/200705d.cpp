#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    priority_queue<ll> pq;
    vector<ll> vec;
    ll input;
    for (int i = 0;i < n;i++) {
        cin >> input;
        pq.push(input);
    }

    ll ans = pq.top();
    vec.push_back(pq.top());
    vec.push_back(pq.top()); pq.pop();
    vec.insert(vec.begin() + 1, pq.top()); pq.pop();

    while(!pq.empty()) {
        ll tmp = pq.top(); pq.pop();
        ll m = 0;
        int idx = 1;
        for (int i = 1;i < vec.size();i++) {
            ll a = min(vec[i - 1], vec[i]);
            if (m < a) {
                m = a;
                idx = i;
            }
        }

        ans += m;
        vec.insert(vec.begin() + idx, tmp);
    }

    cout << ans << endl;
    /*
    for (int i = 0;i < vec.size();i++) {
        cout << "vec:" << vec[i] << endl;
    }
    */

    return(0);
}
