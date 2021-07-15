#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    vector<ll> vec;

    for (int i = 0;i < n;i++) {
        ll input;
        cin >> input;
        vec.push_back(input);
    }

    sort(vec.begin(), vec.end(), greater<ll>());

    for (int i = 0;i < vec.size();i++) {
        ll temp = vec[i];
        bool f = true;
        for (int j = i + 1;j < vec.size() && f;j++) {
            if (temp % vec[j] == 0) {
                
                f = false;
            }
        }

        if (f) ans++;
    }

    cout << ans << endl;

    return 0;
}
