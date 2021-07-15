#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool t[10000005] = {};

int main() {
    ll n;
    cin >> n;
    ll ans = 0;

    for (int i = 2;i <= n;i++) {
        if (!t[i]) {
            for (int j = i + i;j <= n;j+=i) {
                t[j] = true;
            }
        }
    }

    vector<int> q;
    for (int i = 2;i <= n;i++) {
        if(!t[i]) q.push_back(i);
    }

    for (int i = 1;i <= n;i++) {
        ll tmp = 1;
        if (i == 1) tmp = 1;
        else if (!t[i]) tmp = 2;
        else {
            int j = i;
            for (int k = 0;k < q.size();k++) {
                int now = q[k];
                int cnt = 0;
                while (j % now == 0) {
                    j /= now;
                    cnt++;    
                }
                tmp *= (cnt + 1); 
            }  
        }

        // cout << i << ":" << tmp << endl;
        ans += i * tmp;
    }

    cout << ans << endl;

    return 0;
}
